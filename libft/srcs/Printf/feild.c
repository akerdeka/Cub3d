/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feild.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:25:38 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:12:51 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*get_precision(const char *fmt, t_struct *pf)
{
	char	*precision;
	int		j;

	if (fmt[pf->i] == '.')
	{
		pf->flag = ft_strfjoin(pf->flag, ".", 1);
		pf->i++;
	}
	j = pf->i;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (!(precision = malloc(sizeof(char) * ((j - pf->i) + 1))))
		return (NULL);
	j = 0;
	while (fmt[pf->i] >= '0' && fmt[pf->i] <= '9')
	{
		precision[j] = fmt[pf->i];
		pf->i++;
		j++;
	}
	precision[j] = '\0';
	pf->precision = ft_atoi((const char *)precision);
	free(precision);
	return (NULL);
}

void		*get_width(const char *fmt, t_struct *pf)
{
	char	*width;
	int		j;

	j = pf->i;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (!(width = malloc(sizeof(char) * ((j - pf->i) + 1))))
		return (NULL);
	j = 0;
	while (fmt[pf->i] >= '0' && fmt[pf->i] <= '9')
	{
		width[j] = fmt[pf->i];
		pf->i++;
		j++;
	}
	width[j] = '\0';
	pf->width = ft_atoi((const char *)width);
	free(width);
	return (NULL);
}

static void	*get_flag_norm(const char *fmt, t_struct *pf, int j)
{
	char	*gflag;
	int		x;

	x = 0;
	if (!(gflag = malloc(sizeof(char) * ((j - pf->i) + 1))))
		return (NULL);
	j = 0;
	while (fmt[pf->i] == '0' || fmt[pf->i] == '-' || fmt[pf->i] == '*' ||
		fmt[pf->i] == '.')
	{
		if (fmt[pf->i] == '0' && x == 1)
			gflag[j] = ' ';
		else
			gflag[j] = fmt[pf->i];
		if (fmt[pf->i] == '.')
			x = 1;
		pf->i++;
		j++;
	}
	gflag[j] = '\0';
	pf->flag = ft_strdup(gflag);
	free(gflag);
	return (NULL);
}

void		*get_flag(const char *fmt, t_struct *pf)
{
	int		j;

	j = pf->i;
	while (fmt[j] == '0' || fmt[j] == '-' || fmt[j] == '*' || fmt[j] == '.')
		j++;
	get_flag_norm(fmt, pf, j);
	return (NULL);
}

void		get_feild(const char *fmt, t_struct *pf)
{
	int k;

	k = 0;
	pf->i++;
	if (fmt[pf->i] > '0' && fmt[pf->i] <= '9')
		get_width(fmt, pf);
	get_flag(fmt, pf);
	if (ft_strchr(pf->flag, '*'))
	{
		star_converter(pf);
		k = 1;
	}
	if (pf->width == 0 && (!(ft_strchr(pf->flag, '.'))))
		get_width(fmt, pf);
	if (pf->precision == 0)
		get_precision(fmt, pf);
	if (fmt[pf->i] == '*')
		pf->flag = ft_strfjoin(pf->flag, "*", 1);
	if (ft_strchr(pf->flag, '*') && k == 0)
	{
		star_converter(pf);
		pf->i++;
	}
}
