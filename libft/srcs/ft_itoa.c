/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:14:44 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:04:35 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compte(int n)
{
	int		mem;

	mem = 1;
	if (n < 0)
	{
		n = n * -1;
		mem++;
	}
	while (n >= 10)
	{
		mem++;
		n = n / 10;
	}
	return (mem);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = ft_compte(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	res[i--] = '\0';
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		res[i] = ('0' + (n % 10));
		n = n / 10;
		i--;
	}
	return (res);
}
