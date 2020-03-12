/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:19:27 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/12 13:24:51 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		search_walls(t_cub_struct *cub)
{
	cub->map.x = (int)cub->pos.x;
	cub->map.y = (int)cub->pos.y;
	cub->delta_dist.x = fabs(1 / cub->ray_dir.x);
	cub->delta_dist.y = fabs(1 / cub->ray_dir.y);
	cub->hit = 0;
	if (cub->ray_dir.x < 0)
	{
		cub->step.x = -1;
		cub->side_dist.x = (cub->pos.x - cub->map.x) * cub->delta_dist.x;
	}
	else
	{
		cub->step.x = 1;
		cub->side_dist.x = (cub->map.x + 1.0 - cub->pos.x) * cub->delta_dist.x;
	}
	if (cub->ray_dir.y < 0)
	{
		cub->step.y = -1;
		cub->side_dist.y = (cub->pos.y - cub->map.y) * cub->delta_dist.y;
	}
	else
	{
		cub->step.y = 1;
		cub->side_dist.y = (cub->map.y + 1.0 - cub->pos.y) * cub->delta_dist.y;
	}
}

static void		DDA(t_cub_struct *cub)
{
	cub->door = 0;
	while (cub->hit == 0)
	{
		if (cub->side_dist.x < cub->side_dist.y)
		{
			cub->side_dist.x += cub->delta_dist.x;
			cub->map.x += cub->step.x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist.y += cub->delta_dist.y;
			cub->map.y += cub->step.y;
			cub->side = 1;
		}
		if (cub->world_map[cub->map.x][cub->map.y] == '1')
			cub->hit = 1;
		if (cub->world_map[cub->map.x][cub->map.y] == '3')
		{
			cub->hit = 1;
			cub->door = 1;
		}
	}
}

static void		setup_draw(t_cub_struct *c)
{
	if (c->side == 0)
		c->walldist =
			(c->map.x - c->pos.x + (1 - c->step.x) / 2) / c->ray_dir.x;
	else
		c->walldist =
			(c->map.y - c->pos.y + (1 - c->step.y) / 2) / c->ray_dir.y;
	c->line_height = (int)(c->res_win[2] / c->walldist);
	c->draw_start = -c->line_height / 2 + c->res_win[2] / 2;
	if (c->draw_start < 0)
		c->draw_start = 0;
	c->draw_end = c->line_height / 2 + c->res_win[2] / 2;
	if (c->draw_end >= c->res_win[2])
		c->draw_end = c->res_win[2] - 1;
}

int				raycast(t_cub_struct *cub)
{
	int		x;

	x = 0;
	load_text(cub);
	while (x <= cub->res_win[1] - 1)
	{
		cub->camerax = 2 * x / (double)cub->res_win[1] - 1;
		cub->ray_dir.x = cub->dir.x + cub->plane.x * cub->camerax;
		cub->ray_dir.y = cub->dir.y + cub->plane.y * cub->camerax;
		search_walls(cub);
		DDA(cub);
		setup_draw(cub);
		apply_textures(cub);
		draw(cub, x);
		cub->zbuffer[x] = cub->walldist;
		x++;
	}
	sprite_raycast(cub);
	return (1);
}
