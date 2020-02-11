/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 16:01:54 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 13:26:34 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color		*initvar_color(void)
{
	t_color *setup;

	if (!(setup = malloc(sizeof(t_color))))
		ft_printf("Malloc failed");
	setup->color = 0;
	setup->rgb.a = 0;
	setup->rgb.b = 0;
	setup->rgb.r = 0;
	setup->rgb.g = 0;
	return (setup);
}

t_cub_struct		*initvar_cub(void)
{
	t_cub_struct	*cub;

	if (!(cub = malloc(sizeof(t_cub_struct) * 1)))
		return (NULL);
	cub->i = 0;
	cub->map = NULL;
	cub->fmt = NULL;
	cub->color = initvar_color();
	cub->color_f = 0;
	cub->color_c = 0;
	cub->nb_line = 0;
	cub->map_lenght = 0;
	return (cub);
}

int					cub3d(t_cub_struct *cub, char **ag)
{
	if (!ag[1])
		return (0);
	cub->map = ag[1];
	parsing(cub);
	free(cub);
	return (0);
}

int					main(int ac, char **ag)
{
	ac = 0;
	cub3d(initvar_cub(), ag);
	return (0);
}
