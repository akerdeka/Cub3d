/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:10:41 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:42:41 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

void			dpf_ft_algo(const char *fmt, t_dpf_struct *pf)
{
	if (fmt[pf->i] != '%')
		dpf_get_basic(fmt, pf);
	if (fmt[pf->i] != '\0')
	{
		dpf_get_feild(fmt, pf);
		pf->type = fmt[pf->i];
		if (ft_strchr("cspdiuxX%", pf->type))
		{
			if (!(ft_strchr(pf->flag, '.') && pf->precision == 0 &&
				pf->type == 's'))
				dpf_convert(pf);
			dpf_gest_flag(pf);
		}
	}
}

t_dpf_struct		*dpf_initvar(void)
{
	t_dpf_struct	*pf;

	if (!(pf = malloc(sizeof(t_dpf_struct) * 1)))
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

static void		dpf_reinitvar(t_dpf_struct *pf)
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

static void		ft_dprintf_norme(int fd, const char *fmt, t_dpf_struct *pf)
{
	while (fmt[pf->i] != '\0')
	{
		dpf_ft_algo(fmt, pf);
		if (pf->base_write != NULL)
		{
			write(fd, pf->base_write, ft_strlen(pf->base_write));
			pf->final_result += ft_strlen(pf->base_write);
		}
		if (pf->result != NULL)
		{
			if (pf->cnull == 1 && ft_strchr(pf->flag, '-'))
				write(fd, "", 1);
			write(fd, pf->result, ft_strlen(pf->result));
			pf->final_result += ft_strlen(pf->result);
			if (pf->cnull == 1 && (!(ft_strchr(pf->flag, '-'))))
				write(fd, "", 1);
		}
		dpf_reinitvar(pf);
		if (fmt[pf->i] == '\0')
			break ;
		pf->i++;
	}
}

int				ft_dprintf(int fd, const char *fmt, ...)
{
	t_dpf_struct	*pf;
	int			j;

	pf = dpf_initvar();
	va_start(pf->ap, fmt);
	ft_dprintf_norme(fd, fmt, pf);
	va_end(pf->ap);
	j = pf->final_result;
	free(pf);
	return (j);
}
