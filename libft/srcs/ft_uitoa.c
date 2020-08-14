/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:44 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:07:40 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_compte(unsigned int n)
{
	int				mem;

	mem = 1;
	while (n >= 10)
	{
		mem++;
		n = n / 10;
	}
	return (mem);
}

char				*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	char			*res;

	i = ft_compte(n);
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	res[i--] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[i] = ('0' + (n % 10));
		n = n / 10;
		i--;
	}
	return (res);
}
