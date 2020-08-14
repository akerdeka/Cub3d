/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:21:01 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:04:53 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(unsigned long long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_maj(unsigned long long value, int base)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;

	if (value == 0)
		return (ft_strdup("0"));
	if (!(tab_base = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	taille = digit_count(value, base);
	if (!(ret = malloc(sizeof(char) * (taille + 1))))
		return (NULL);
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	free(tab_base);
	ret[taille] = '\0';
	return (ret);
}
