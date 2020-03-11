/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:56:49 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/11 14:23:52 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		all_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_set_color(t_cub_struct *cub, char *token)
{
	int		color;

	color = ft_atoi(token);
	if (color < 0 || color > 255)
		error(cub, 4);
	return (color);
}

void	f_converter(t_cub_struct *cub)
{
	if (all_digit(cub->color_flor[1]))
		cub->color->rgb.r = ft_set_color(cub, cub->color_flor[1]);
	else
		error(cub, 4);
	if (all_digit(cub->color_flor[2]))
		cub->color->rgb.g = ft_set_color(cub, cub->color_flor[2]);
	else
		error(cub, 4);
	if (all_digit(cub->color_flor[3]))
		cub->color->rgb.b = ft_set_color(cub, cub->color_flor[3]);
	else
		error(cub, 4);
	cub->color_f = cub->color->color;
	ft_printf("color : %d\n\n", cub->color_f);
}
