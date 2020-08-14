/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrif_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 11:13:41 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/12 11:39:20 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	verrifmap4(t_cub_struct *cub, char *line, int endmap, int check_map)
{
	int			i;

	i = 0;
	while (endmap != 1 && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '0')
		error(cub, 1);
	if (line[0] != '\0' && check_map == 1)
		error(cub, 1);
}

static int	verrif_map_3(t_cub_struct *cub, char *line, int is_map_closed)
{
	int			i;

	i = 0;
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
	return (is_map_closed);
}

static int	verrif_map_2(t_cub_struct *cub, char *line, int player)
{
	if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'W') ||
		ft_strchr(line, 'E'))
	{
		get_pos_player(cub, line);
		player++;
	}
	return (player);
}

int			verrif_map(t_cub_struct *cub, char *line, int end_map)
{
	static int		player = 0;
	static int		check_map = 0;
	static int		is_map_closed = 0;

	player = verrif_map_2(cub, line, player);
	if (line[0] == '\0' && end_map != 1)
	{
		if (player != 1)
			error(cub, 2);
		check_map = 1;
		return (0);
	}
	is_map_closed = verrif_map_3(cub, line, is_map_closed);
	verrifmap4(cub, line, end_map, check_map);
	if (end_map == 1)
	{
		if (is_map_closed == 0)
			error(cub, 1);
		if (ft_strchr(line, 'N') || ft_strchr(line, 'S') ||
			ft_strchr(line, 'W') || ft_strchr(line, 'E'))
			player++;
		if (player != 1)
			error(cub, 2);
	}
	return (0);
}
