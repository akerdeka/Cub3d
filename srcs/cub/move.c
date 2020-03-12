/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:27:11 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/12 13:31:32 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		move(t_cub_struct *cub)
{
	if (cub->key_vert == 'W')
	{
		cub->pos.x += cub->dir.x * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.x -= cub->dir.x * MOVESPEED * cub->key_sprint;
		cub->pos.y += cub->dir.y * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.y -= cub->dir.y * MOVESPEED * cub->key_sprint;
	}
	if (cub->key_vert == 'S')
	{
		cub->pos.x -= cub->dir.x * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.x += cub->dir.x * MOVESPEED * cub->key_sprint;
		cub->pos.y -= cub->dir.y * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.y += cub->dir.y * MOVESPEED * cub->key_sprint;
	}
	if (cub->key_hor == 'A')
	{
		cub->pos.x -= cub->plane.x * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.x += cub->plane.x * MOVESPEED * cub->key_sprint;
		cub->pos.y -= cub->plane.y * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.y += cub->plane.y * MOVESPEED * cub->key_sprint;
	}
	if (cub->key_hor == 'D')
	{
		cub->pos.x += cub->plane.x * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.x -= cub->plane.x * MOVESPEED * cub->key_sprint;
		cub->pos.y += cub->plane.y * MOVESPEED * cub->key_sprint;
		if (cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '1' ||
		cub->world_map[(int)cub->pos.x][(int)cub->pos.y] == '3')
			cub->pos.y -= cub->plane.y * MOVESPEED * cub->key_sprint;
	}
	if (cub->key_rot == ARROW_RIGHT)
	{
		cub->old_dir.y = cub->dir.y;
		cub->dir.y = cub->dir.y * cos(ROTSPEED) - cub->dir.x * sin(ROTSPEED);
		cub->dir.x = cub->old_dir.y * sin(ROTSPEED) + cub->dir.x * cos(ROTSPEED);
		cub->old_plane.y = cub->plane.y;
		cub->plane.y = cub->plane.y * cos(ROTSPEED)
		- cub->plane.x * sin(ROTSPEED);
		cub->plane.x = cub->old_plane.y * sin(ROTSPEED)
		+ cub->plane.x * cos(ROTSPEED);
	}
	if (cub->key_rot == ARROW_LEFT)
	{
		cub->old_dir.y = cub->dir.y;
		cub->dir.y = cub->dir.y * cos(-ROTSPEED) - cub->dir.x * sin(-ROTSPEED);
		cub->dir.x = cub->old_dir.y * sin(-ROTSPEED) + cub->dir.x * cos(-ROTSPEED);
		cub->old_plane.y = cub->plane.y;
		cub->plane.y = cub->plane.y * cos(-ROTSPEED)
		- cub->plane.x * sin(-ROTSPEED);
		cub->plane.x = cub->old_plane.y * sin(-ROTSPEED)
		+ cub->plane.x * cos(-ROTSPEED);
	}
	cub->map.x = (int)cub->pos.x;
	cub->map.y = (int)cub->pos.y;
}

void		restart(t_cub_struct *cub)
{
	cub->pos.x = cub->pos_x_player + 0.5;
	cub->pos.y = cub->pos_y_player + 0.5;
}