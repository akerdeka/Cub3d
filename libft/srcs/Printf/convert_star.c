/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_star.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 16:38:12 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 17:32:07 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	*star_converter(t_struct *pf)
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
