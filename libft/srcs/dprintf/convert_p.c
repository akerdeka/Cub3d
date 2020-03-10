/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:59:19 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:35:13 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

char	*dpf_p_converter(unsigned long value, t_dpf_struct *pf)
{
	char	*res;

	pf->type_check = 1;
	res = ft_itoa_base(value, 16);
	if (ft_strchr(pf->flag, '.') && value == 0)
	{
		free(res);
		res = ft_strdup("0x");
	}
	else
	{
		res = ft_strfjoin("0x", res, 2);
	}
	return (res);
}
