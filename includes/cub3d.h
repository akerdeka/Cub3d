/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:02:35 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/09 15:04:15 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./keycode.h"
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/srcs/Printf/libftprintf.h"
# include "../libft/srcs/dprintf/libftdprintf.h"
# define FOV 66
# define MOVESPEED 0.073
# define ROTSPEED 0.04

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgb;

typedef union		u_color
{
	int				color;
	t_rgb			rgb;
}					t_color;

typedef struct		s_img
{
	void			*img;
	int				width;
	int				height;
	int				*img_data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;


typedef struct		s_cub_struct
{
	int			i;
	char		*map_cub;
	char		*fmt;
	char		*res[4];
	int			res_win[4];
	char		*tex_no[3];
	char		*tex_so[3];
	char		*tex_we[3];
	char		*tex_ea[3];
	char		*tex_sprite[3];
	char		*color_flor[5];
	char		*color_ceiling[5];
	char		**world_map;
	t_color		*color;
	t_vector	pos;
	t_vector	plane;
	t_vector	old_plane;
	t_pos		map;
	t_vector	dir;
	t_vector	old_dir;
	t_vector	ray_dir;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_pos		step;
	int			texNum;
	t_vector	tex;
	int			tex_y;
	int			tex_x;
	t_vector	wall;
	double		walldist;
	char		key_vert;
	char		key_hor;
	char		key_rot;
	t_img		*screen;
	t_img		text[4];
	double		tex_step;
	double		tex_pos;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			hit;
	int			side;
	double		camerax;
	char		dir_player;
	int			pos_x_player;
	int			pos_y_player;
	int			color_f;
	int			color_c;
	int			map_lenght;
	int			nb_line;
	void		*mlx_ptr;
	void		*mlx_win;
}					t_cub_struct;

int		cub3d(t_cub_struct *cub, char **ag);
int		error(t_cub_struct *cub, int type);
int		parsing(t_cub_struct *cub);
int		get_map(t_cub_struct *cub, char *line, int end_map);
int		stock_map(t_cub_struct *cub, char *line, char *new_line);
char	*clear_spaces(char *line);
int		get_texture_no(t_cub_struct *cub, char *line);
int		get_texture_so(t_cub_struct *cub, char *line);
int		get_texture_we(t_cub_struct *cub, char *line);
int		get_texture_ea(t_cub_struct *cub, char *line);
int		get_texture_sprite(t_cub_struct *cub, char *line);
void	f_converter(t_cub_struct *cub);
void	c_converter_cub(t_cub_struct *cub);
void	ft_exit(t_cub_struct *cub);
int		ft_cub(t_cub_struct *cub);
int		ft_close(t_cub_struct *cub);
void	init_player(t_cub_struct *cub);
int		raycast(t_cub_struct *cub);
void	move(t_cub_struct *cub);
void	draw(t_cub_struct *cub, int x);
void	restart(t_cub_struct *cub);
void	load_text(t_cub_struct *cub);
void	apply_textures(t_cub_struct *cub);

#endif
