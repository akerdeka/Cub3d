/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:23:32 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:39:43 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

static char	*conv_char_to_string(char c, t_dpf_struct *pf)
{
	char	*res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	if (c == '\0')
	{
		pf->cnull = 1;
		pf->final_result += 1;
	}
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char		*dpf_c_converter(t_dpf_struct *pf)
{
	char	*value;

	value = conv_char_to_string(va_arg(pf->ap, int), pf);
	return (value);
}