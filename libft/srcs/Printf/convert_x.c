/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:03:14 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:26:31 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*x_converter(t_struct *pf)
{
	char					*res;
	unsigned int			ag;

	pf->type_check = 1;
	res = NULL;
	if (pf->type == 'x')
	{
		if (((ag = va_arg(pf->ap, unsigned int)) == 0) &&
			ft_strchr(pf->flag, '.') && pf->precision == 0)
			res = ft_strdup("");
		else
			res = ft_itoa_base(ag, 16);
	}
	else
	{
		if (((ag = va_arg(pf->ap, unsigned int)) == 0) &&
			ft_strchr(pf->flag, '.') && pf->precision == 0)
			res = ft_strdup("");
		else
			res = ft_itoa_base_maj(ag, 16);
	}
	return (res);
}