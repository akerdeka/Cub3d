/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:42:30 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:38:48 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

void	dpf_convert(t_dpf_struct *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->conv_result = dpf_di_converter(pf);
	else if (pf->type == 's')
		pf->conv_result = dpf_s_converter(va_arg(pf->ap, char *), pf);
	else if (pf->type == 'c')
		pf->conv_result = dpf_c_converter(pf);
	else if (pf->type == 'u')
		pf->conv_result = dpf_u_converter(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		pf->conv_result = dpf_x_converter(pf);
	else if (pf->type == 'p')
		pf->conv_result = dpf_p_converter(va_arg(pf->ap, unsigned long), pf);
	else if (pf->type == '%')
	{
		pf->type_check = 1;
		pf->conv_result = dpf_percent_converter();
	}
}
