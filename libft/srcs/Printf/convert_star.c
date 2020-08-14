/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:38:12 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:12:08 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*star_converter(t_struct *pf)
{
	int		j;

	j = -1;
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
