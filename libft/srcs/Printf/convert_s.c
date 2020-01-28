/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 14:52:38 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:39:52 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*s_converter(char *str, t_struct *pf)
{
	pf->type_check = 1;
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
