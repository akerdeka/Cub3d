/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:36:37 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:34:48 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

char	*dpf_di_converter(t_dpf_struct *pf)
{
	char	*value;
	long	ag;

	if (((ag = va_arg(pf->ap, int)) == 0) && ft_strchr(pf->flag, '.')
		&& pf->precision == 0)
		value = ft_strdup("");
	else
	{
		if (ag < 0)
		{
			if (!(ft_strchr(pf->flag, '.') && (pf->precision == 0 ||
				pf->precision == 1)) && ft_strchr(pf->flag, '0'))
				pf->width -= 1;
			pf->neg = 1;
			ag = ag * -1;
		}
		value = ft_itoa(ag);
	}
	pf->type_check = 1;
	return (value);
}
