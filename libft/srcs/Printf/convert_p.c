/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_p.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 14:59:19 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:24:45 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*p_converter(unsigned long value, t_struct *pf)
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
