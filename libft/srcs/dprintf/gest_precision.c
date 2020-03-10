/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:06:31 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/17 15:43:18 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftdprintf.h"

void	*dpf_gest_prec_zero(t_dpf_struct *pf)
{
	pf->result = ft_strdup("0");
	return (NULL);
}

void	*dpf_gest_precision(t_dpf_struct *pf)
{
	char	*tmp;

	if ((pf->precision > ft_strlen(pf->conv_result)) && pf->type != 's')
		dpf_flag_zero_prec(pf);
	else if ((pf->precision < ft_strlen(pf->conv_result)) && pf->type == 's')
	{
		tmp = ft_strndup(pf->conv_result, pf->precision);
		free(pf->conv_result);
		pf->conv_result = ft_strdup(tmp);
		free(tmp);
	}
	else if (pf->precision < ft_strlen(pf->conv_result) && (pf->type != 'd' &&
		pf->type != 'i'))
		dpf_flag_zero_prec(pf);
	return (NULL);
}

void	*dpf_flag_zero_prec(t_dpf_struct *pf)
{
	char	*res;
	int		nb_zero;
	int		i;

	i = -1;
	nb_zero = pf->precision - ft_strlen(pf->conv_result);
	if (!(res = malloc(sizeof(char) * (pf->precision + 1))))
		return (NULL);
	while (++i < nb_zero)
		res[i] = '0';
	res[i] = '\0';
	pf->conv_result = ft_strfjoin(res, pf->conv_result, 0);
	return (NULL);
}
