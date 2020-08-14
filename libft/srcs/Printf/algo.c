/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:36:05 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:11:20 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*get_basic(const char *fmt, t_struct *pf)
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
