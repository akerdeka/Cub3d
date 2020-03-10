/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:02:11 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/09 17:07:53 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/cub3d.h"

static int		f_checker(t_cub_struct *cub, char *line)
{
	int i;

	i = 0;
	cub->color_flor[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->color_flor[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[3] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[4] = ft_strtok(NULL, " ,\t");
	while (i < 5)
	{
		ft_printf("%s\n", cub->color_flor[i]);
		i++;
	}
	ft_printf("\n");
	if (cub->color_flor[4] != NULL || cub->color_flor[3] == NULL)
		error(cub, 0);
	f_converter(cub);
	return (0);
}

static int		c_checker(t_cub_struct *cub, char *line)
{
	int i;

	i = 0;
	cub->color_ceiling[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->color_ceiling[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[3] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[4] = ft_strtok(NULL, " ,\t");
	while (i < 5)
	{
		ft_printf("%s\n", cub->color_ceiling[i]);
		i++;
	}
	ft_printf("\n");
	if (cub->color_ceiling[4] != NULL || cub->color_ceiling[3] == NULL)
		error(cub, 0);
	c_converter_cub(cub);
	return (0);
}

static int		r_checker(t_cub_struct *cub, char *line)
{
	int	i;

	i = 0;
	cub->res[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->res[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->res[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->res[3] = ft_strtok(NULL, " \t");
	while (i < 4)
	{
		ft_printf("%s\n", cub->res[i]);
		i++;
	}
	if (cub->res[3] != NULL || cub->res[2] == NULL)
		error(cub, 0);
	// all digit ??
	i = 1;
	while (i <= 2)
	{
		cub->res_win[i] = ft_atoi(cub->res[i]);
		if (cub->res_win[i] <= 0)
			error(cub, 4);
		i++;
	}
	ft_printf("\n");
	return (0);
}

int				get_infos(t_cub_struct *cub, char *line, int end_map)
{
	static int	check = 0;

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
	else if (line[0] == 'S' && cub->tex_sprite[0] == NULL)
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
	return (0);
}

int				parsing(t_cub_struct *cub)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	fd = open(cub->map_cub, O_RDONLY);
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
