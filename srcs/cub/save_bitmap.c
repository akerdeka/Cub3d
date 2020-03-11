/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:49:21 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/11 16:26:46 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_bitmap_image(t_cub_struct *c, int fd, t_bpm2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = c->res_win[2] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->res_win[1])
		{
			ble = c->screen->img_data[y * c->res_win[1] + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void			ft_save_bitmap(const char *filename, t_cub_struct *c)
{
	int			fd;
	t_bpm		bfh;
	t_bpm2		bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = c->res_win[1] * c->res_win[2] * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = c->res_win[1];
	bih.height = c->res_win[2];
	bih.planes = 1;
	bih.bit_count = 32;
	bih.compression = 0;
	bih.image_size = c->res_win[1] * c->res_win[2] * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	ft_bitmap_image(c, fd, bih);
}