/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:27:56 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:12:50 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../../includes/libft.h"

typedef struct	s_struct
{
	int			i;
	char		*base_write;
	char		*flag;
	char		type;
	int			width;
	int			precision;
	int			nb_space;
	char		*spaces;
	int			neg;
	int			cnull;
	int			type_check;
	char		*conv_result;
	char		*result;
	int			final_result;
	va_list		ap;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				algo(const char *fmt);
void			*get_basic(const char *fmt, t_struct *pf);
void			get_feild(const char *fmt, t_struct *pf);
void			*get_flag(const char *fmt, t_struct *pf);
void			*get_width(const char *fmt, t_struct *pf);
void			*get_precision(const char *fmt, t_struct *pf);
void			*star_converter(t_struct *pf);
void			convert(t_struct *pf);
char			*di_converter(t_struct *pf);
char			*c_converter(t_struct *pf);
char			*s_converter(char *str, t_struct *pf);
char			*u_converter(t_struct *pf);
char			*x_converter(t_struct *pf);
char			*p_converter(unsigned long value, t_struct *pf);
char			*percent_converter(void);
void			gest_flag(t_struct *pf);
void			*flag_zero(t_struct *pf);
void			*get_spaces(t_struct *pf, char *res);
char			*flag_dash(t_struct *pf);
void			*gest_precision(t_struct *pf);
void			*gest_prec_zero(t_struct *pf);
void			*flag_zero_prec(t_struct *pf);

#endif
