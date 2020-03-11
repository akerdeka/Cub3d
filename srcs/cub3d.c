/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:01:54 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/11 16:11:53 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color				*initvar_color(void)
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
	ft_bzero(cub->res, sizeof(char *) * 29);
	cub->i = 0;
	cub->map_cub = NULL;
	cub->flag = 0;
	cub->world_map = 0;
	cub->fmt = NULL;
	cub->color = initvar_color();
	cub->color_f = 0;
	cub->color_c = 0;
	cub->dir_player = 0;
	cub->pos_x_player = 0;
	cub->pos_y_player = 0;
	cub->nb_line = 0;
	cub->map_lenght = 0;
	cub->hit = 0;
	cub->side = 0;
	cub->Numsprite = 0;
	return (cub);
}

static void		check_map_name(t_cub_struct *cub)
{
	size_t	i;

	i = 0;
	while (cub->map_cub[i] && cub->map_cub[i] != '.')
		i++;
	if (!(cub->map_cub[i] == '.' && cub->map_cub[i + 1] == 'c' &&
	cub->map_cub[i + 2] == 'u' && cub->map_cub[i + 3] == 'b'))
		error(cub, 5);
}

int				cub3d(t_cub_struct *cub,int ac, char **ag)
{
	if (ac > 3)
	{
		ft_printf("Error\nToo much arguments");
		exit(1);
	}
	if (!ag[1])
		error(cub, 5);
	if (!(cub->map_cub = ag[1]))
		exit(1);
	if (ac == 3 && !ft_strncmp(ag[2], "--save", 7))
		cub->flag = 's';
	check_map_name(cub);
	parsing(cub);
	ft_cub(cub);
	free(cub);
	return (0);
}

int					main(int ac, char **ag)
{
	cub3d(initvar_cub(),ac, ag);
	return (0);
}
