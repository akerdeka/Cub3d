/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 16:02:35 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:26:13 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "../libft/srcs/Printf/libftprintf.h"


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

typedef struct		s_cub_struct
{
	int			i;
	char		*res[4];
	char		*map;
	char		*fmt;
	char		*tex_no[3];
	char		*tex_so[3];
	char		*tex_we[3];
	char		*tex_ea[3];
	char		*tex_sprite[3];
	t_color		*color;
	char		*color_flor[5];
	char		*color_ceiling[5];
	int			color_f;
	int			color_c;
	int			map_lenght;
	int			nb_line;
}					t_cub_struct;

int		cub3d(t_cub_struct *cub, char **ag);
int		error(int type);
int		parsing(t_cub_struct *cub);
int		get_map(t_cub_struct *cub, char *line, int end_map);
int		get_texture_no(t_cub_struct *cub, char *line);
int		get_texture_so(t_cub_struct *cub, char *line);
int		get_texture_we(t_cub_struct *cub, char *line);
int		get_texture_ea(t_cub_struct *cub, char *line);
int		get_texture_sprite(t_cub_struct *cub, char *line);
void	f_converter(t_cub_struct *cub);
void	c_converter_cub(t_cub_struct *cub);

#endif
