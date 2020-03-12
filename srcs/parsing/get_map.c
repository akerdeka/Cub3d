/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:46:08 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/12 12:12:40 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	lastcheckmap(t_cub_struct *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cub->world_map[i])
	{
		while (cub->world_map[i][j])
		{
			if (cub->world_map[i][j] == ' ' && i != cub->nb_line && cub->world_map[i + 1][j] == '0')
				error(cub, 1);
			if (cub->world_map[i][j] == ' ' && i != 0 && cub->world_map[i - 1][j] == '0')
				error(cub, 1);
			if (cub->world_map[i][j] == ' ' && j != 0 && cub->world_map[i][j - 1] == '0')
				error(cub, 1);
			if (cub->world_map[i][j] == ' ' && cub->world_map[i][j + 1] == '0')
				error(cub, 1);
			j++;
		}
		i++;
		j = 0;
	}
}

char		*clear_spaces(char *line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i + j])
	{
		if (line[i + j] == ' ' || line[i + j] == '\t')
			j++;
		i++;
	}
	res = malloc(sizeof(char) * i + 1);
	i = 0;
	j = 0;
	while (line[i + j])
	{
		if (line[i + j] == ' ' || line[i + j] == '\t')
			j++;
		res[i] = line[i + j];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int				stock_map(t_cub_struct *cub, char *line, char *new_line)
{
	int		i = 0;
	int		j = 0;
	new_line = ft_strfjoin(new_line, line, 1);
	new_line = ft_strfjoin(new_line, "\n", 1);
	cub->world_map = ft_split(new_line, '\n');
	while (cub->world_map[i])
	{
		while (cub->world_map[i][j])
		{
			if (cub->world_map[i][j] == '1')
				ft_printf("\033[1;31m%c", cub->world_map[i][j]);
			else
				ft_printf("\033[1;30m%c", cub->world_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
		j = 0;
	}
	lastcheckmap(cub);
	return (1);
}
