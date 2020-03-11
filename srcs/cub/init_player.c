/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:39:56 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/10 19:11:39 by akerdeka         ###   ########lyon.fr   */
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
	cub->key_sprint = 1;
}

void			init_player(t_cub_struct *cub)
{
	int		x;
	int		y;
	int		i;

	i = 0;	
	x = 0;
	y = 0;
	cub->pos.x = (double)cub->pos_x_player + (double)0.5;
	cub->pos.y = (double)cub->pos_y_player + (double)0.5;
	initvdir(cub);
	initplane(cub);
	while(cub->world_map[y])
	{
		x = 0 ;
		while (cub->world_map[y][x])
		{
			if (cub->world_map[y][x] == '2')
			{
				cub->Numsprite++;
			}
			x++;
		}
		y++;
	}
	cub->sprite = malloc(sizeof(t_sprite) * cub->Numsprite);
	cub->zbuffer = malloc(sizeof(double) * (cub->res_win[1] + 1));
	cub->spriteorder = malloc(sizeof(int) * cub->Numsprite);
	cub->spritedist = malloc(sizeof(double) * cub->Numsprite);
	x = 0;
	y = 0;
	while(cub->world_map[y])
	{
		x = 0 ;
		while (cub->world_map[y][x])
		{
			if (cub->world_map[y][x] == '2')
			{
				cub->sprite[i].y = x + 0.5;
				cub->sprite[i].x = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}