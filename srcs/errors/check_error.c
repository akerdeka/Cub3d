/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 14:46:15 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 18:10:11 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		error(int type)
{
	if (type == 0)
		ft_printf("Error\nNeed R  &&  NO-SO-WE-EA-S  &&  F-C\n");
	if (type == 1)
		ft_printf("Error\nMap error\n");
	if (type == 2)
		ft_printf("Error\nToo many/no player on map\n");
	if (type == 3)
		ft_printf("Error\nNewline forbidden in deffinition of map or after\n");
	if (type == 4)
		ft_printf("Error\nNot a valid number\n");
	exit(0);
	return (-1);
}