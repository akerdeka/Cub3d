/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:36:05 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:34:36 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

void	*dpf_get_basic(const char *fmt, t_dpf_struct *pf)
{
	char	*base;
	int		j;

	j = pf->i;
	while (fmt[j] != '%')
		j++;
	if (!(base = malloc(sizeof(char) * ((j - pf->i) + 1))))
		return (NULL);
	j = -1;
	while (fmt[pf->i] != '%' && fmt[pf->i] != '\0')
	{
		base[++j] = fmt[pf->i];
		pf->i++;
	}
	base[++j] = '\0';
	pf->base_write = ft_strdup(base);
	free(base);
	return (NULL);
}
