/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:07:19 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:06:48 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!(res = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	if (!(s[i] == '\0'))
	{
		while (s[i] != '\0')
		{
			res[i] = (*f)(i, (char)s[i]);
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
