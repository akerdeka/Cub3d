/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:09:53 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/12 17:58:04 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		swap_sprites(t_cub_struct *c, int i)
{
	t_sprite	tmp;

	tmp = c->sprite[i + 1];
	c->sprite[i + 1] = c->sprite[i];
	c->sprite[i] = tmp;
}

static void		sort_sprites(t_cub_struct *c)
{
	int i;

	i = 0;
	while (i < c->Numsprite)
	{
		c->sprite[i].dist = sqrt((c->pos.x - c->sprite[i].x) *
			(c->pos.x - c->sprite[i].x) +
			((c->pos.y - c->sprite[i].y) *
			(c->pos.y - c->sprite[i].y)));
		i++;
	}
	i = 0;
	while (i < c->Numsprite - 1)
	{
		if (c->sprite[i].dist < c->sprite[i + 1].dist)
		{
			swap_sprites(c, i);
			i = 0;
		}
		i++;
	}
	i = 0;
}

void		sprite_raycast(t_cub_struct *cub)
{
	int		i;

	i = 0;
	while (i < cub->Numsprite)
	{
		cub->spriteorder[i] = i;
		cub->spritedist[i] = ((cub->pos.x - cub->sprite[i].x) *
		(cub->pos.x - cub->sprite[i].x) + (cub->pos.y - cub->sprite[i].y) *
		(cub->pos.y - cub->sprite[i].y));
		i++;
	}
	sort_sprites(cub);
	draw_sprites(cub);
}