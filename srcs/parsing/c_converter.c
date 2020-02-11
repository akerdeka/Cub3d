/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c_converter.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 18:51:35 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 18:04:43 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	int		all_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_set_color(char *token)
{
	int		color;

	color = ft_atoi(token);
	if (color < 0 || color > 255)
		error(4);
	return (color);
}

void	c_converter_cub(t_cub_struct *cub)
{
	if (all_digit(cub->color_ceiling[1]))
		cub->color->rgb.r = ft_set_color(cub->color_ceiling[1]);
	else
		error(4);
	if (all_digit(cub->color_ceiling[2]))
		cub->color->rgb.g = ft_set_color(cub->color_ceiling[2]);
	else
		error(4);
	if (all_digit(cub->color_ceiling[3]))
		cub->color->rgb.b = ft_set_color(cub->color_ceiling[3]);
	else
		error(4);
	cub->color_c = cub->color->color;
	ft_printf("color : %d\n\n", cub->color_c);
}
