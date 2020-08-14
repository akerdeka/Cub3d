/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:02:35 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/13 12:08:42 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include "./keycode.h"
# include "../libmlx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/srcs/Printf/libftprintf.h"
# include "../libft/srcs/dprintf/libftdprintf.h"
# define FOV 66
# define MOVESPEED 0.073
# define ROTSPEED 0.04

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

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

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
	double			dist;
}					t_sprite;

typedef struct		s_cub_struct
{
	int				i;
	char			*map_cub;
	char			*fmt;
	char			*res[4];
	int				res_win[4];
	char			*tex_no[3];
	char			*tex_so[3];
	char			*tex_we[3];
	char			*tex_ea[3];
	char			*tex_sprite[3];
	char			*color_flor[5];
	char			*color_ceiling[5];
	char			**world_map;
	t_color			*color;
	t_vector		pos;
	t_vector		plane;
	t_vector		old_plane;
	t_pos			map;
	t_vector		dir;
	t_vector		old_dir;
	t_vector		ray_dir;
	t_vector		delta_dist;
	t_vector		side_dist;
	t_pos			step;
	t_sprite		*sprite;
	int				texnum;
	int				numsprite;
	t_vector		tex;
	int				tex_y;
	int				tex_x;
	t_vector		wall;
	double			walldist;
	double			*zbuffer;
	double			*spritedist;
	int				*spriteorder;
	double			invdet;
	t_vector		transform;
	int				sprite_scrn_x;
	int				sprite_height;
	int				sprite_width;
	t_pos			sprite_start;
	t_pos			sprite_end;
	int				stripe;
	char			key_vert;
	char			key_hor;
	int				key_rot;
	char			key_sprint;
	char			key_act;
	t_img			*screen;
	t_img			text[6];
	double			tex_step;
	double			tex_pos;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				side;
	double			camerax;
	char			dir_player;
	int				pos_x_player;
	int				pos_y_player;
	int				color_f;
	int				color_c;
	int				map_lenght;
	int				nb_line;
	void			*mlx_ptr;
	void			*mlx_win;
	double			spritex;
	double			spritey;
	char			flag;
	char			door;
}					t_cub_struct;

int					cub3d(t_cub_struct *cub, int ac, char **ag, t_color *setup);
int					error(t_cub_struct *cub, int type);
int					parsing(t_cub_struct *cub);
int					get_map(t_cub_struct *cub, char *line, int end_map);
int					verrif_map(t_cub_struct *cub, char *line, int end_map);
int					stock_map(t_cub_struct *cub, char *line, char *new_line);
int					get_pos_player(t_cub_struct *cub, char *line);
char				*clear_spaces(char *line);
int					get_texture_no(t_cub_struct *cub, char *line);
int					get_texture_so(t_cub_struct *cub, char *line);
int					get_texture_we(t_cub_struct *cub, char *line);
int					get_texture_ea(t_cub_struct *cub, char *line);
int					get_texture_sprite(t_cub_struct *cub, char *line);
int					all_digit(char *str);
int					f_checker(t_cub_struct *cub, char *line);
int					c_checker(t_cub_struct *cub, char *line);
int					r_checker(t_cub_struct *cub, char *line);
void				f_converter(t_cub_struct *cub);
void				c_converter_cub(t_cub_struct *cub);
void				ft_exit(t_cub_struct *cub);
int					ft_cub(t_cub_struct *cub);
int					ft_close(t_cub_struct *cub);
void				init_player(t_cub_struct *cub);
int					raycast(t_cub_struct *cub);
void				move(t_cub_struct *cub);
void				draw(t_cub_struct *cub, int x);
void				restart(t_cub_struct *cub);
void				load_text(t_cub_struct *cub);
void				apply_textures(t_cub_struct *cub);
void				draw_sprites(t_cub_struct *cub);
void				sprite_raycast(t_cub_struct *cub);
void				ft_save_bitmap(const char *filename, t_cub_struct *game);

#endif
