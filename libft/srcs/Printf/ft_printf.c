/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:10:41 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:12:51 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_algo(const char *fmt, t_struct *pf)
{
	if (fmt[pf->i] != '%')
		get_basic(fmt, pf);
	if (fmt[pf->i] != '\0')
	{
		get_feild(fmt, pf);
		pf->type = fmt[pf->i];
		if (ft_strchr("cspdiuxX%", pf->type))
		{
			if (!(ft_strchr(pf->flag, '.') && pf->precision == 0 &&
				pf->type == 's'))
				convert(pf);
			gest_flag(pf);
		}
	}
}

t_struct		*initvar(void)
{
	t_struct	*pf;

	if (!(pf = malloc(sizeof(t_struct) * 1)))
		return (NULL);
	pf->i = 0;
	pf->base_write = NULL;
	pf->flag = NULL;
	pf->type = 0;
	pf->width = 0;
	pf->precision = 0;
	pf->nb_space = 0;
	pf->spaces = NULL;
	pf->neg = 0;
	pf->cnull = 0;
	pf->type_check = 0;
	pf->conv_result = NULL;
	pf->result = NULL;
	pf->final_result = 0;
	return (pf);
}

static void		reinitvar(t_struct *pf)
{
	if (pf->base_write != NULL)
		free(pf->base_write);
	pf->base_write = NULL;
	if (pf->flag != NULL)
		free(pf->flag);
	pf->flag = NULL;
	pf->type = 0;
	pf->width = 0;
	pf->precision = 0;
	pf->nb_space = 0;
	if (pf->spaces != NULL)
		free(pf->spaces);
	pf->spaces = NULL;
	pf->neg = 0;
	pf->cnull = 0;
	pf->type_check = 0;
	if (pf->conv_result != NULL)
		free(pf->conv_result);
	pf->conv_result = NULL;
	if (pf->result != NULL)
		free(pf->result);
	pf->result = NULL;
}

static void		ft_printf_norme(const char *fmt, t_struct *pf)
{
	while (fmt[pf->i] != '\0')
	{
		ft_algo(fmt, pf);
		if (pf->base_write != NULL)
		{
			write(1, pf->base_write, ft_strlen(pf->base_write));
			pf->final_result += ft_strlen(pf->base_write);
		}
		if (pf->result != NULL)
		{
			if (pf->cnull == 1 && ft_strchr(pf->flag, '-'))
				write(1, "", 1);
			write(1, pf->result, ft_strlen(pf->result));
			pf->final_result += ft_strlen(pf->result);
			if (pf->cnull == 1 && (!(ft_strchr(pf->flag, '-'))))
				write(1, "", 1);
		}
		reinitvar(pf);
		if (fmt[pf->i] == '\0')
			break ;
		pf->i++;
	}
}

int				ft_printf(const char *fmt, ...)
{
	t_struct	*pf;
	int			j;

	pf = initvar();
	va_start(pf->ap, fmt);
	ft_printf_norme(fmt, pf);
	va_end(pf->ap);
	j = pf->final_result;
	free(pf);
	return (j);
}
