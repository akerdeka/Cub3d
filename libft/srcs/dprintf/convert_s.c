/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:52:38 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:10:31 by akerdeka         ###   ########lyon.fr   */
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
