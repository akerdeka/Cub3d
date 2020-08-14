/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:36:31 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/11 16:50:37 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_sprites_2(t_cub_struct *c)
{
	if (c->sprite_end.y >= c->res_win[2])
		c->sprite_end.y = c->res_win[2] - 1;
	c->sprite_width = abs((int)(c->res_win[2] / c->transform.y));
	c->sprite_start.x = -c->sprite_width / 2 + c->sprite_scrn_x;
	if (c->sprite_start.x < 0)
		c->sprite_start.x = 0;
	c->sprite_end.x = c->sprite_width / 2 + c->sprite_scrn_x;
	if (c->sprite_end.x >= c->res_win[1])
		c->sprite_end.x = c->res_win[1] - 1;
	c->stripe = c->sprite_start.x;
}

static void	draw_sprites_3(t_cub_struct *c, int y, int d)
{
	while (c->stripe < c->sprite_end.x)
	{
		c->tex_x = (int)((256 * (c->stripe - (-c->sprite_width / 2 +
			c->sprite_scrn_x)) * c->text[4].width / c->sprite_width) / 256);
		if (c->transform.y > 0 && c->stripe < c->res_win[1] &&
			c->transform.y < c->zbuffer[c->stripe])
		{
			y = c->sprite_start.y;
			while (y < c->sprite_end.y)
			{
				d = y * 256 - c->res_win[2] * 128 + c->sprite_height * 128;
				c->tex_y = ((d * c->text[4].width) / c->sprite_height) /
					256;
				c->color->color = c->text[4].img_data[c->tex_y *
					c->text[4].width + c->tex_x];
				if ((c->color->color & 0xffffff) != 0)
					c->screen->img_data[y * c->res_win[1] + c->stripe] =
						c->color->color;
				y++;
			}
		}
		c->stripe++;
	}
}

void		draw_sprites(t_cub_struct *c)
{
	int		i;
	int		y;
	int		d;

	i = 0;
	while (i < c->numsprite)
	{
		c->spritex = c->sprite[c->spriteorder[i]].x - c->pos.x;
		c->spritey = c->sprite[c->spriteorder[i]].y - c->pos.y;
		c->invdet = 1.0 / (c->plane.x * c->dir.y - c->dir.x * c->plane.y);
		c->transform.x = c->invdet * (c->dir.y * c->spritex -
			c->dir.x * c->spritey);
		c->transform.y = c->invdet * (-c->plane.y * c->spritex +
			c->plane.x * c->spritey);
		c->sprite_scrn_x = (int)((c->res_win[1] / 2) *
			(1 + c->transform.x / c->transform.y));
		c->sprite_height = abs((int)(c->res_win[2] / c->transform.y));
		c->sprite_start.y = -c->sprite_height / 2 + c->res_win[2] / 2;
		if (c->sprite_start.y < 0)
			c->sprite_start.y = 0;
		c->sprite_end.y = c->sprite_height / 2 + c->res_win[2] / 2;
		draw_sprites_2(c);
		draw_sprites_3(c, y, d);
		i++;
	}
}
