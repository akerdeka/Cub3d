/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtok.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 14:44:55 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:15:02 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

size_t		ft_strspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

size_t		ft_strcspn(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

char		*ft_strtok(char *s, const char *charset)
{
	char			*end;
	static char		*save_str;

	if (s == NULL)
		s = save_str;
	if (*s == '\0')
	{
		save_str = s;
		return (NULL);
	}
	s += ft_strspn(s, charset);
	if (*s == '\0')
	{
		save_str = s;
		return (NULL);
	}
	end = s + ft_strcspn(s, charset);
	if (*end == '\0')
	{
		save_str = end;
		return (s);
	}
	*end = '\0';
	save_str = end + 1;
	return (s);
}
