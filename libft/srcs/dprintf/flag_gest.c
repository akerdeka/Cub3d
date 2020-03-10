/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_gest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:41:57 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:41:47 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libftdprintf.h"

void		*dpf_flag_zero(t_dpf_struct *pf)
{
	char	*res;
	int		width;
	int		i;

	i = -1;
	width = pf->width - ft_strlen(pf->conv_result);
	if (pf->neg == 1 && width < 0)
		pf->width += 1;
	if (!(res = malloc(sizeof(char) * (pf->width + 1))))
		return (NULL);
	while (++i < width)
		res[i] = '0';
	res[i] = '\0';
	if (pf->neg == 1)
		res = ft_strfjoin("-", res, 2);
	pf->result = ft_strfjoin(res, pf->conv_result, 1);
	return (NULL);
}

char		*dpf_flag_dash(t_dpf_struct *pf)
{
	char	*res;

	res = NULL;
	if (ft_strchr(pf->flag, '-'))
		res = ft_strjoin(pf->conv_result, pf->spaces);
	else
		res = ft_strjoin(pf->spaces, pf->conv_result);
	return (res);
}

void		*dpf_get_spaces(t_dpf_struct *pf, char *res)
{
	int		i;

	i = 0;
	if (pf->width < 0)
	{
		pf->width = -1 * pf->width;
		pf->flag = ft_strfjoin(pf->flag, "-", 1);
	}
	if (pf->width > ft_strlen(res))
	{
		pf->nb_space += pf->width - ft_strlen(res);
		if (pf->neg == 1)
			pf->nb_space -= 1;
	}
	if (pf->cnull == 1)
		pf->nb_space -= 1;
	if (!(pf->spaces = malloc(sizeof(char) * (pf->nb_space + 1))))
		return (NULL);
	while (pf->nb_space--)
		pf->spaces[i++] = ' ';
	pf->spaces[i] = '\0';
	return (NULL);
}

static void	gest_flag_norme(t_dpf_struct *pf, int i)
{
	if (pf->neg == 1)
	{
		if (i == 0)
			pf->spaces = ft_strdup("");
		pf->conv_result = ft_strfjoin("-", pf->conv_result, 2);
		i = 1;
	}
	if (pf->result == NULL)
	{
		if (i == 0)
			pf->spaces = ft_strdup("");
		pf->result = dpf_flag_dash(pf);
	}
}

void		dpf_gest_flag(t_dpf_struct *pf)
{
	int		i;

	i = 0;
	if (pf->precision > 0 && pf->type != '%')
		dpf_gest_precision(pf);
	else if (ft_strchr(pf->flag, '0') && pf->type_check == 1 &&
		pf->type != 's' && (!(ft_strchr(pf->flag, '-'))))
	{
		if (!(ft_strchr(pf->flag, '.') && (pf->precision == 0)))
			dpf_flag_zero(pf);
	}
	else if (pf->precision == 0 && ft_strchr(pf->flag, '.') && pf->type == 's')
	{
		free(pf->conv_result);
		pf->conv_result = ft_strdup("");
	}
	if (pf->width != 0)
	{
		dpf_get_spaces(pf, pf->conv_result);
		i = 1;
	}
	gest_flag_norme(pf, i);
}
