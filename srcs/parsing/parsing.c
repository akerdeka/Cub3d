/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:02:11 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/11 13:34:31 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/cub3d.h"

static int	get_infos_2(t_cub_struct *cub, char *line, int end_map, int a)
{
	static int	check = 0;

	if (a == 1)
	{
		if (line[0] == 'S' && cub->tex_sprite[0] == NULL)
			get_texture_sprite(cub, line);
		else if (line[0] == 'F' && cub->color_flor[0] == NULL)
			f_checker(cub, line);
		else if (line[0] == 'C' && cub->color_ceiling[0] == NULL)
			c_checker(cub, line);
		else if (check == 0 && end_map != 1 && line[0] == '\0')
			return (0);
		else if (cub->res[0] == NULL || cub->tex_no[0] == NULL ||
			cub->tex_so[0] == NULL || cub->tex_we[0] == NULL ||
			cub->tex_ea[0] == NULL || cub->tex_sprite[0] == NULL ||
			cub->color_flor[0] == NULL || cub->color_ceiling[0] == NULL)
			return (-1);
		else
		{
			check = 1;
			get_map(cub, line, end_map);
		}
	}
	return (0);
}

int			get_infos(t_cub_struct *cub, char *line, int end_map)
{
	int			a;

	a = 0;
	if (line == NULL)
		error(cub, 5);
	if (line[0] == 'R' && cub->res[0] == NULL)
		r_checker(cub, line);
	else if (line[0] == 'N' && line[1] == 'O' && cub->tex_no[0] == NULL)
		get_texture_no(cub, line);
	else if (line[0] == 'S' && line[1] == 'O' && cub->tex_so[0] == NULL)
		get_texture_so(cub, line);
	else if (line[0] == 'W' && line[1] == 'E' && cub->tex_we[0] == NULL)
		get_texture_we(cub, line);
	else if (line[0] == 'E' && line[1] == 'A' && cub->tex_ea[0] == NULL)
		get_texture_ea(cub, line);
	else
		a = 1;
	if (get_infos_2(cub, line, end_map, a) == -1)
		return (-1);
	return (0);
}

int			parsing(t_cub_struct *cub)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if (!(fd = open(cub->map_cub, O_RDONLY)))
		error(cub, 5);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (get_infos(cub, line, 0) == -1)
			error(cub, 0);
		free(line);
	}
	if (get_infos(cub, line, 1) == -1)
		error(cub, 0);
	free(line);
	close(fd);
	return (0);
}
