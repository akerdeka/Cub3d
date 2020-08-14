/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:23:22 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:07:25 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = ft_strlen(s);
	if ((start >= j) || (len == 0))
		return (ft_calloc(sizeof(char), 1));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > i)
	{
		str[i] = (char)s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
