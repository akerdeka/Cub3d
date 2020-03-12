/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:55:32 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/11 18:18:22 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_pos_player(t_cub_struct *cub, char *line)
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
		else if (line[i] == 'N')
		{
			cub->dir_player = 'N';
			break ;
		}
		else if (line[i] == 'S')
		{
			cub->dir_player = 'S';
			break ;
		}
		else if (line[i] == 'W')
		{
			cub->dir_player = 'W';
			break ;
		}
		else if (line[i] == 'E')
		{
			cub->dir_player = 'E';
			break ;
		}
		i++;
	}
	cub->pos_x_player = cub->nb_line - 1;
	cub->pos_y_player = i - j;
	return (1);
}

int		verrif_map(t_cub_struct *cub, char *line, int end_map)
{
	static int		player = 0;
	int				i;
	static int		check_map = 0;
	static int		is_map_closed = 0;

	i = 0;
	i = 0;
	if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'W') ||
		ft_strchr(line, 'E'))
	{
		get_pos_player(cub, line);
		player++;
	}
	if (line[0] == '\0' && end_map != 1)
	{
		if (player != 1)
			error(cub, 2);
		check_map = 1;
		return (0);
	}
	while (line[i] && cub->nb_line == 1)
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			error(cub, 1);
		i++;
	}
	while (line[i] && cub->nb_line != 1)
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
		{
			is_map_closed = 0;
			break ;
		}
		else
			is_map_closed = 1;
		i++;
	}
	i = 0;
	while (end_map != 1 && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '0')
		error(cub, 1);
	if (line[0] != '\0' && check_map == 1)
		error(cub, 1);
	if (end_map == 1)
	{
		if (is_map_closed == 0)
			error(cub, 1);
		if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'W') ||
			ft_strchr(line, 'E'))
			player++;
		if (player != 1)
			error(cub, 2);
	}
	return (0);
}

int		get_map(t_cub_struct *cub, char *line, int end_map)
{
	int			i;
	int			j;
	int			map_lenght_check;
	static char	*new_line = NULL;

	i = 0;
	j = 0;
	if (new_line == NULL)
		new_line = ft_strdup("");
	map_lenght_check = cub->map_lenght;
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
	i = ft_strlen(line);
	while (end_map != 1 && i < cub->map_lenght)
	{
		new_line = ft_strfjoin(new_line, " ", 1);
		i++;
	}
	new_line = ft_strfjoin(new_line, "\n", 1);
	if (end_map == 1)
		stock_map(cub, line, new_line);
	return (0);
}
