/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:53:05 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:37:46 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

char	*dpf_u_converter(t_dpf_struct *pf)
{
	char	*value;
	int		ag;

	pf->type_check = 1;
	if (((ag = va_arg(pf->ap, unsigned int)) == 0) && ft_strchr(pf->flag, '.')
		&& pf->precision == 0)
		value = ft_strdup("");
	else
		value = ft_uitoa(ag);
	return (value);
}