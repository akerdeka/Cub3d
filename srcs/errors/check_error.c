/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:46:15 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 07:54:03 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		error(t_cub_struct *cub, int type)
{
	if (type == 0)
		ft_dprintf(2, "Error\nNeed R  &&  NO-SO-WE-EA-S  &&  F-C\n");
	if (type == 1)
		ft_dprintf(2, "Error\nMap error\n");
	if (type == 2)
		ft_dprintf(2, "Error\nToo many/no player on map\n");
	if (type == 3)
		ft_dprintf(2,
			"Error\nNewline forbidden in deffinition of map or after\n");
	if (type == 4)
		ft_dprintf(2, "Error\nNot a valid number\n");
	if (type == 5)
		ft_dprintf(2, "Error\nInvalid map\n");
	if (type == 6)
		ft_dprintf(2, "Error\nInvalid texture(s)\n");
	free(cub);
	exit(0);
}
