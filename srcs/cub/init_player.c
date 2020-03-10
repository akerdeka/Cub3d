/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:39:56 by akerdeka          #+#    #+#             */
/*   Updated: 2020/02/24 18:44:51 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		initvdir(t_cub_struct *cub)
{
	if (cub->dir_player == 'E')
	{
		cub->dir.x = 0;
		cub->dir.y = 1;
	}
	else if (cub->dir_player == 'S')
	{
		cub->dir.x = 1;
		cub->dir.y = 0;
	}
	else if (cub->dir_player == 'N')
	{
		cub->dir.x = -1;
		cub->dir.y = 0;
	}
	else if (cub->dir_player == 'W')
	{
		cub->dir.x = 0;
		cub->dir.y = -1;
	}
}

static void		initplane(t_cub_struct *cub)
{
	if (cub->dir_player == 'E')
	{
		cub->plane.x = ((double)FOV / (double)100);
		cub->plane.y = 0;
	}
	else if (cub->dir_player == 'N')
	{
		cub->plane.x = 0;
		cub->plane.y = ((double)FOV / (double)100);
	}
	else if (cub->dir_player == 'S')
	{
		cub->plane.x = 0;
		cub->plane.y = -((double)FOV / (double)100);
	}
	else if (cub->dir_player == 'W')
	{
		cub->plane.x = -((double)FOV / (double)100);
		cub->plane.y = 0;
	}
}

void			init_player(t_cub_struct *cub)
{
	cub->pos.x = (double)cub->pos_x_player + (double)0.5;
	cub->pos.y = (double)cub->pos_y_player + (double)0.5;
	initvdir(cub);
	initplane(cub);
}