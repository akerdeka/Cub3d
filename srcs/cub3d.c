/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:01:54 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/05 12:35:18 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color		*initvar_color(void)
{
	t_color *setup;

	if (!(setup = malloc(sizeof(t_color))))
		ft_printf("Malloc failed");
	setup->color = 0;
	setup->rgb.a = 0;
	setup->rgb.b = 0;
	setup->rgb.r = 0;
	setup->rgb.g = 0;
	return (setup);
}

t_cub_struct		*initvar_cub(void)
{
	t_cub_struct	*cub;

	if (!(cub = malloc(sizeof(t_cub_struct) * 1)))
		return (NULL);
	ft_bzero(cub->res, sizeof(char *) * 29);
	cub->i = 0;
	cub->map_cub = NULL;
	cub->world_map = 0;
	cub->fmt = NULL;
	cub->color = initvar_color();
	cub->color_f = 0;
	cub->color_c = 0;
	cub->dir_player = 0;
	cub->pos_x_player = 0;
	cub->pos_y_player = 0;
	cub->nb_line = 0;
	cub->map_lenght = 0;
	cub->hit = 0;
	cub->side = 0;
	return (cub);
}

int					cub3d(t_cub_struct *cub, char **ag)
{
	if (!ag[1])
		return (0);
	cub->map_cub = ag[1];
	parsing(cub);
	ft_cub(cub);
	free(cub);
	return (0);
}

int					main(int ac, char **ag)
{
	ac = 0;
	cub3d(initvar_cub(), ag);
	return (0);
}
