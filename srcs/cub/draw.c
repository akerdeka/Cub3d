/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:14:21 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 07:38:43 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_flor(t_cub_struct *cub, int x)
{
	int		y;

	y = cub->res_win[2] - 1;
	while (y >= cub->draw_end)
	{
		cub->screen->img_data[y * cub->res_win[1] + x] = cub->color_f;
		y--;
	}
}

static void	draw_ceiling(t_cub_struct *cub, int x)
{
	int		y;

	y = 0;
	while (y < cub->draw_start)
	{
		cub->screen->img_data[y * cub->res_win[1] + x] = cub->color_c;
		y++;
	}
}

static void	draw_wall(t_cub_struct *cub, int x)
{
	int		y;

	y = cub->draw_start;
	while (y < cub->draw_end)
	{
		cub->tex_y = (int)cub->tex_pos & (cub->text[cub->texnum].height - 1);
		cub->tex_pos += cub->tex_step;
		cub->color->color = cub->text[cub->texnum].img_data[cub->tex_y *
			cub->text[cub->texnum].width + cub->tex_x];
		cub->screen->img_data[y * cub->res_win[1] + x] = cub->color->color;
		y++;
	}
}

void		draw(t_cub_struct *cub, int x)
{
	draw_wall(cub, x);
	draw_flor(cub, x);
	draw_ceiling(cub, x);
}
