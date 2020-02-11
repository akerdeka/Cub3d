/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 13:55:32 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:41:59 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// int		is_map_closed(t_cub_struct *cub, char *line)
// {
// 	int				i;
// 	static int		j = 1;

// 	i = 0;
// 	while (j == 1 && line[i])
// 	{
// 		if (line[i] != '1')
// 		{
// 			j = 1;
// 			return (1);
// 		}
// 		i++;
// 	}
// 	if (j == 0 && line[0] != '\0')
// 		error(cub, 1);
// 	j = 0;
// 	return (0);
// }

int		verrif_map(t_cub_struct *cub, char *line, int end_map)
{
	static int		player = 0;
	int				i;

	i = 0;
	if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'W') ||
		ft_strchr(line, 'E'))
		player++;
	while (line[i] && cub->nb_line == 1)
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			error(1);
		i++;
	}
	if (line[0] == '\0' || (line[0] != '1' || line[ft_strlen(line) - 1] != '1'))
		error(3);
	if (end_map == 1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
				error(1);
			i++;
		}
		if (ft_strchr(line, 'N') || ft_strchr(line, 'S') ||
			ft_strchr(line, 'W') || ft_strchr(line, 'E'))
			player++;
		if (player != 1)
			error(2);
	}
	return (0);
}

int		get_map(t_cub_struct *cub, char *line, int end_map)
{
	size_t		i;
	int			map_lenght_check;

	i = 0;
	map_lenght_check = cub->map_lenght;
	cub->map_lenght = 0;
	while (line[i + cub->map_lenght])
	{
		while (ft_strchr(" \t", line[i + cub->map_lenght]))
			i++;
		cub->map_lenght++;
	}
	if (line[0] != '\0' && map_lenght_check != 0 && map_lenght_check != cub->map_lenght)
		error(1);
	cub->nb_line++;
	ft_printf("%s\n", line);
	verrif_map(cub, line, end_map);
	return (0);
}
