/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:32:04 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/12 13:20:04 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main_loop(t_cub_struct *cub)
{
	move(cub);
	raycast(cub);
	if (cub->key_act == 1)
	{
		if (cub->world_map[(int)(cub->pos.x + cub->dir.x)][(int)(cub->pos.y + cub->dir.y)] == '3')
			cub->world_map[(int)(cub->pos.x + cub->dir.x)][(int)(cub->pos.y + cub->dir.y)] = '0';
		cub->key_act = 0;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win, cub->screen->img, 0, 0);
	return (1);
}

int		ft_close(t_cub_struct *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	ft_exit(cub);
	return (1);
}

int		ft_key_press(int keycode, t_cub_struct *cub)
{
	if (keycode == KEY_ESC)
		ft_close(cub);
	if (keycode == KEY_Q)
		restart(cub);
	if (keycode == KEY_LSHIFT)
		cub->key_sprint = 2;
	if (keycode == KEY_W)
		cub->key_vert = 'W';
	else if (keycode == KEY_S)
		cub->key_vert = 'S';
	else if (keycode == KEY_A)
		cub->key_hor = 'A';
	else if (keycode == KEY_D)
		cub->key_hor = 'D';
	else if (keycode == ARROW_RIGHT)
		cub->key_rot = ARROW_RIGHT;
	else if (keycode == ARROW_LEFT)
		cub->key_rot = ARROW_LEFT;
	return (1);
}

int		ft_key_release(int keycode, t_cub_struct *cub)
{
	if (keycode == KEY_W)
		cub->key_vert = 0;
	else if (keycode == KEY_S)
		cub->key_vert = 0;
	else if (keycode == KEY_LSHIFT)
		cub->key_sprint = 1;
	else if (keycode == KEY_A)
		cub->key_hor = 0;
	else if (keycode == KEY_D)
		cub->key_hor = 0;
	else if (keycode == ARROW_RIGHT)
		cub->key_rot = 0;
	else if (keycode == ARROW_LEFT)
		cub->key_rot = 0;
	else if (keycode == KEY_SPACE)
		cub->key_act = 1;
	return (1);
}

int		ft_cub(t_cub_struct *cub)
{
	if ((cub->mlx_ptr = mlx_init()) == NULL)
		ft_exit(cub);
	init_player(cub);
	cub->screen = malloc(sizeof(t_img) * 1);
	if ((cub->mlx_win = mlx_new_window(cub->mlx_ptr, cub->res_win[1], cub->res_win[2], "Cub3D")) == NULL)
		ft_exit(cub);
	cub->screen->img = mlx_new_image(cub->mlx_ptr, cub->res_win[1], cub->res_win[2] + 1);
	cub->screen->img_data = 
		(int *)mlx_get_data_addr(cub->screen->img, &cub->screen->bpp,
		&cub->screen->size_line, &cub->screen->endian);
	if (cub->flag == 's')
	{
		raycast(cub);
		ft_save_bitmap("screenshot.bmp", cub);
	}
	mlx_hook(cub->mlx_win, 2, 0, &ft_key_press, cub);
	mlx_hook(cub->mlx_win, 3, 0, &ft_key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, &ft_close, cub);
	mlx_loop_hook(cub->mlx_ptr, &main_loop, cub);
	mlx_loop(cub->mlx_ptr);
	ft_exit(cub);
	return (0);
}
