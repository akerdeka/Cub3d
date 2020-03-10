/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:52:38 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:37:30 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

char	*dpf_s_converter(char *str, t_dpf_struct *pf)
{
	pf->type_check = 1;
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
