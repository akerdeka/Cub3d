/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 11:42:30 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 16:03:43 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert(t_struct *pf)
{
	if (pf->type == 'd' || pf->type == 'i')
		pf->conv_result = di_converter(pf);
	else if (pf->type == 's')
		pf->conv_result = s_converter(va_arg(pf->ap, char *), pf);
	else if (pf->type == 'c')
		pf->conv_result = c_converter(pf);
	else if (pf->type == 'u')
		pf->conv_result = u_converter(pf);
	else if (pf->type == 'x' || pf->type == 'X')
		pf->conv_result = x_converter(pf);
	else if (pf->type == 'p')
		pf->conv_result = p_converter(va_arg(pf->ap, unsigned long), pf);
	else if (pf->type == '%')
	{
		pf->type_check = 1;
		pf->conv_result = percent_converter();
	}
}
