/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 16:01:54 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 18:54:45 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub_struct		*initvar(void)
{
	t_cub_struct	*cub;

	if (!(cub = malloc(sizeof(t_cub_struct) * 1)))
		return (NULL);
	cub->i = 0;
	cub->res_x = 0;
	cub->res_y = 0;
	cub->map = NULL;
	cub->tex_NO = NULL;
	cub->tex_SO = NULL;
	cub->tex_WE = NULL;
	cub->tex_EA = NULL;
	cub->color_F = 0;
	cub->color_C = 0;
	return (cub);
}

void	cub3d(t_cub_struct *cub, char **ag)
{
	cub->map = ft_strdup(ag[1]);
	parsing(cub);
}

int main(int ac, char **ag)
{
	ac = 0;
	cub3d(initvar(), ag);
}