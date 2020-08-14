/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:28:09 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:05:05 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*temp;

	temp = s;
	while (n != 0)
	{
		if ((char)*temp == c)
			return ((char *)temp);
		n--;
		temp++;
	}
	return (0);
}
