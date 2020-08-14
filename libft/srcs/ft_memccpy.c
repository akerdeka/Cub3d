/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:35:35 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:05:01 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*ptrdest;
	char	*ptrsrc;

	i = 0;
	ptrdest = (char *)dest;
	ptrsrc = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	while (n > 0)
	{
		ptrdest[i] = ptrsrc[i];
		if (ptrsrc[i] == (char)c)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (0);
}
