/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 16:29:24 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 16:31:09 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s[i] != '\0' && n > 0)
	{
		res[i] = s[i];
		i++;
		n--;
	}
	res[i] = '\0';
	return (res);
}
