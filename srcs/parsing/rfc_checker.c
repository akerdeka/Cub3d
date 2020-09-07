/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfc_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:06:59 by akerdeka          #+#    #+#             */
/*   Updated: 2020/09/07 13:21:42 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/cub3d.h"

int		f_checker(t_cub_struct *cub, char *line)
{
	if (ft_countchar(line, ',') != 2)
		error(cub, 0);
	cub->color_flor[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->color_flor[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[3] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_flor[4] = ft_strtok(NULL, " ,\t");
	if (cub->color_flor[4] != NULL || cub->color_flor[3] == NULL)
		error(cub, 0);
	f_converter(cub);
	return (0);
}

int		c_checker(t_cub_struct *cub, char *line)
{
	if (ft_countchar(line, ',') != 2)
		error(cub, 0);
	cub->color_ceiling[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->color_ceiling[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[3] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->color_ceiling[4] = ft_strtok(NULL, " ,\t");
	if (cub->color_ceiling[4] != NULL || cub->color_ceiling[3] == NULL)
		error(cub, 0);
	c_converter_cub(cub);
	return (0);
}

int		r_checker(t_cub_struct *cub, char *line)
{
	int	i;

	i = 0;
	cub->res[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->res[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->res[2] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->res[3] = ft_strtok(NULL, " \t");
	if (cub->res[3] != NULL || cub->res[2] == NULL)
		error(cub, 0);
	i = 1;
	while (i <= 2)
	{
		if (all_digit(cub->res[i]) == 0)
			error(cub, 4);
		cub->res_win[i] = ft_atoi(cub->res[i]);
		if (cub->res_win[i] <= 0)
			error(cub, 4);
		if (cub->res_win[i] < 500)
			cub->res_win[i] = 500;
		if (cub->res_win[i] > 2000)
			cub->res_win[i] = 2000;
		i++;
	}
	return (0);
}
