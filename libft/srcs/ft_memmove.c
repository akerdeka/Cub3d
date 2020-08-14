/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:45:30 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:05:23 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*desti;

	i = 0;
	source = (unsigned char *)src;
	desti = (unsigned char *)dest;
	if (desti > source)
	{
		while (n >= ++i)
			desti[n - i] = source[n - i];
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
