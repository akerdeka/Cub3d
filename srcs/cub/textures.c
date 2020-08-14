/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:34:24 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 07:50:13 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		apply_textures(t_cub_struct *cub)
{
	if (cub->side == 0)
		cub->texnum = cub->ray_dir.x < 0 ? 1 : 0;
	else
		cub->texnum = cub->ray_dir.y < 0 ? 2 : 3;
	if (cub->door == 1)
		cub->texnum = 5;
	if (cub->side == 0)
		cub->wall.x = cub->pos.y + cub->walldist * cub->ray_dir.y;
	else
		cub->wall.x = cub->pos.x + cub->walldist * cub->ray_dir.x;
	cub->wall.x -= (int)cub->wall.x;
	cub->tex_x = (int)(cub->wall.x * cub->text[cub->texnum].width);
	if (cub->side == 0 && cub->ray_dir.x > 0)
		cub->tex_x = cub->text[cub->texnum].width - cub->tex_x - 1;
	if (cub->side == 1 && cub->ray_dir.y < 0)
		cub->tex_x = cub->text[cub->texnum].width - cub->tex_x - 1;
	cub->tex_step = 1.0 * cub->text[cub->texnum].height / cub->line_height;
	cub->tex_pos =
		(cub->draw_start - cub->res_win[2] / 2 + cub->line_height / 2) *
		cub->tex_step;
}
