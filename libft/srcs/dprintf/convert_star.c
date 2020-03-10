/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:38:12 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:37:37 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

void	*dpf_star_converter(t_dpf_struct *pf)
{
	int		j;
	int		x;

	j = -1;
	x = 0;
	while (pf->flag[++j] != '\0')
	{
		if (pf->flag[j] == '*')
		{
			if (j == 0 || pf->flag[j - 1] != '.')
				pf->width = va_arg(pf->ap, int);
			else
				pf->precision = va_arg(pf->ap, int);
		}
	}
	return (NULL);
}
