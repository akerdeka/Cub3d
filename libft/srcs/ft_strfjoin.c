/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 15:04:27 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 16:24:49 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	sn_free(char *s1, char *s2, int f)
{
	if (f == 1)
		free(s1);
	else if (f == 2)
		free(s2);
	else
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strfjoin(char *s1, char *s2, int f)
{
	int		i;
	int		j;
	char	*res;

	i = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * (i + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	sn_free(s1, s2, f);
	return (res);
}
