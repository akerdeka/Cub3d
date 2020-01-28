/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 16:02:35 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 18:31:37 by akerdeka    ###    #+. /#+    ###.fr     */
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
# include "../libft/Get_Next_Line/get_next_line.h"
# include "../libft/srcs/Printf/libftprintf.h"


typedef struct	s_cub_struct
{
	int			i;
	int			res_x;
	int			res_y;
	char		*map;
	char		*tex_NO;
	char		*tex_SO;
	char		*tex_WE;
	char		*tex_EA;
	long		color_F;
	long		color_C;
}				t_cub_struct;

void	cub3d(t_cub_struct *cub, char **ag);
void	*parsing(t_cub_struct *cub);

#endif
