/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:04:01 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:01 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		load_no_se_text(t_cub_struct *cub)
{
	if ((cub->text[0].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->tex_so[1], &cub->text[0].width, &cub->text[0].height)))
		cub->text[0].img_data = (int *)mlx_get_data_addr(cub->text[0].img, &cub->text[0].bpp, &cub->text[0].size_line, &cub->text[0].endian);
	else
		exit(1);
	if ((cub->text[1].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->tex_no[1], &cub->text[1].width, &cub->text[1].height)))
		cub->text[1].img_data = (int *)mlx_get_data_addr(cub->text[1].img, &cub->text[1].bpp, &cub->text[1].size_line, &cub->text[1].endian);
	else
		exit(1);
	return (0);
}

static int		load_ea_we_text(t_cub_struct *cub)
{
	if ((cub->text[2].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->tex_we[1], &cub->text[2].width, &cub->text[2].height)))
		cub->text[2].img_data = (int *)mlx_get_data_addr(cub->text[2].img, &cub->text[2].bpp, &cub->text[2].size_line, &cub->text[2].endian);
	else
		exit(1);
	if ((cub->text[3].img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->tex_ea[1], &cub->text[3].width, &cub->text[3].height)))
		cub->text[3].img_data = (int *)mlx_get_data_addr(cub->text[3].img, &cub->text[3].bpp, &cub->text[3].size_line, &cub->text[3].endian);
	else
		exit(1);
	return (0);
}

void			load_text(t_cub_struct *cub)
{
	load_no_se_text(cub);
	load_ea_we_text(cub);
}