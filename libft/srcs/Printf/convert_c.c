/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:23:32 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:12:08 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*conv_char_to_string(char c, t_struct *pf)
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

char		*c_converter(t_struct *pf)
{
	char	*value;

	value = conv_char_to_string(va_arg(pf->ap, int), pf);
	return (value);
}
