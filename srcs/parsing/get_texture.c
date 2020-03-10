/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:47:10 by akerdeka          #+#    #+#             */
/*   Updated: 2020/03/09 15:29:34 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_texture_no(t_cub_struct *cub, char *line)
{
	int i = 0;

	cub->tex_no[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->tex_no[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->tex_no[2] = ft_strtok(NULL, " ,\t");
	while (i < 3)
	{
		ft_printf("%s\n", cub->tex_no[i]);
		i++;
	}
	if (cub->tex_no[2] != NULL || cub->tex_no[1] == NULL)
		error(cub, 0);
	ft_printf("\n");
	return (0);
}

int		get_texture_so(t_cub_struct *cub, char *line)
{
	int i = 0;

	cub->tex_so[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->tex_so[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->tex_so[2] = ft_strtok(NULL, " ,\t");
	while (i < 3)
	{
		ft_printf("%s\n", cub->tex_so[i]);
		i++;
	}
	if (cub->tex_so[2] != NULL || cub->tex_so[1] == NULL)
		error(cub, 0);
	ft_printf("\n");
	return (0);
}

int		get_texture_we(t_cub_struct *cub, char *line)
{
	int	i = 0;

	cub->tex_we[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->tex_we[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->tex_we[2] = ft_strtok(NULL, " ,\t");
	while (i < 3)
	{
		ft_printf("%s\n", cub->tex_we[i]);
		i++;
	}
	if (cub->tex_we[2] != NULL || cub->tex_we[1] == NULL)
		error(cub, 0);
	ft_printf("\n");
	return (0);
}

int		get_texture_ea(t_cub_struct *cub, char *line)
{
	int i = 0;

	cub->tex_ea[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->tex_ea[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->tex_ea[2] = ft_strtok(NULL, " ,\t");
	while (i < 3)
	{
		ft_printf("%s\n", cub->tex_ea[i]);
		i++;
	}
	if (cub->tex_ea[2] != NULL || cub->tex_ea[1] == NULL)
		error(cub, 0);
	ft_printf("\n");
	return (0);
}

int		get_texture_sprite(t_cub_struct *cub, char *line)
{
	int i = 0;

	cub->tex_sprite[0] = ft_strdup(ft_strtok(line, " ,\t"));
	cub->tex_sprite[1] = ft_strdup(ft_strtok(NULL, " ,\t"));
	cub->tex_sprite[2] = ft_strtok(NULL, " ,\t");
	while (i < 3)
	{
		ft_printf("%s\n", cub->tex_sprite[i]);
		i++;
	}
	if (cub->tex_sprite[2] != NULL || cub->tex_sprite[1] == NULL)
		error(cub, 0);
	ft_printf("\n");
	return (0);
}