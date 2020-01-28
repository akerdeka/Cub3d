/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_u.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 16:53:05 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 14:42:59 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*u_converter(t_struct *pf)
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
