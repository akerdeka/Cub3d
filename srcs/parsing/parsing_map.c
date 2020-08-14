/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:32 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/12 16:34:29 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_pos_player_2(t_cub_struct *cub, char *line, int i)
{
	if (line[i] == 'N')
	{
		cub->dir_player = 'N';
	}
	else if (line[i] == 'S')
	{
		cub->dir_player = 'S';
	}
	else if (line[i] == 'W')
	{
		cub->dir_player = 'W';
	}
	else if (line[i] == 'E')
	{
		cub->dir_player = 'E';
	}
	else
		return (0);
	return (1);
}

int			get_pos_player(t_cub_struct *cub, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] && (line[i] != 'N' || line[i] != 'S' || line[i] != 'W' ||
		line[i] != 'E'))
	{
		if (line[i] == ' ')
			j++;
		if (get_pos_player_2(cub, line, i) == 1)
			break ;
		i++;
	}
	cub->pos_x_player = cub->nb_line - 1;
	cub->pos_y_player = i - j;
	return (1);
}

static char	*getmap2(t_cub_struct *cub, char *line, int end_map, char *new_line)
{
	int			i;

	i = ft_strlen(line);
	while (end_map != 1 && i < cub->map_lenght)
	{
		new_line = ft_strfjoin(new_line, " ", 1);
		i++;
	}
	new_line = ft_strfjoin(new_line, "\n", 1);
	if (end_map == 1)
		stock_map(cub, line, new_line);
	free(line);
	return (new_line);
}

int			get_map(t_cub_struct *cub, char *line, int end_map)
{
	int			i;
	int			j;
	static char	*new_line = NULL;

	i = 0;
	j = 0;
	if (new_line == NULL)
		new_line = ft_strdup("");
	while (line[i + j])
	{
		if (line[i + j] == ' ')
			j++;
		else
			i++;
	}
	if (i > cub->map_lenght)
		cub->map_lenght = i;
	cub->nb_line++;
	verrif_map(cub, line, end_map);
	line = clear_spaces(line);
	new_line = ft_strfjoin(new_line, line, 1);
	new_line = getmap2(cub, line, end_map, new_line);
	return (0);
}
