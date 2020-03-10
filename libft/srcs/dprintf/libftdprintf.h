/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftdprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:27:56 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:43:44 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTDPRINTF_H
# define LIBFTDPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../includes/libft.h"

typedef struct	s_dpf_struct
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
}				t_dpf_struct;

int				ft_dprintf(int fd, const char *fmt, ...);
int				dpf_algo(const char *fmt);
void			*dpf_get_basic(const char *fmt, t_dpf_struct *pf);
void			dpf_get_feild(const char *fmt, t_dpf_struct *pf);
void			*dpf_get_flag(const char *fmt, t_dpf_struct *pf);
void			*dpf_get_width(const char *fmt, t_dpf_struct *pf);
void			*dpf_get_precision(const char *fmt, t_dpf_struct *pf);
void			*dpf_star_converter(t_dpf_struct *pf);
void			dpf_convert(t_dpf_struct *pf);
char			*dpf_di_converter(t_dpf_struct *pf);
char			*dpf_c_converter(t_dpf_struct *pf);
char			*dpf_s_converter(char *str, t_dpf_struct *pf);
char			*dpf_u_converter(t_dpf_struct *pf);
char			*dpf_x_converter(t_dpf_struct *pf);
char			*dpf_p_converter(unsigned long value, t_dpf_struct *pf);
char			*dpf_percent_converter(void);
void			dpf_gest_flag(t_dpf_struct *pf);
void			*dpf_flag_zero(t_dpf_struct *pf);
void			*dpf_get_spaces(t_dpf_struct *pf, char *res);
char			*dpf_flag_dash(t_dpf_struct *pf);
void			*dpf_gest_precision(t_dpf_struct *pf);
void			*dpf_gest_prec_zero(t_dpf_struct *pf);
void			*dpf_flag_zero_prec(t_dpf_struct *pf);

#endif
