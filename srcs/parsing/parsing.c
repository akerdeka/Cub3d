/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 16:02:11 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 18:53:33 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../includes/cub3d.h"

void	*parsing(t_cub_struct *cub)
{
	// int		fd;
	// int		ret;
	// char	*line;
	// char	*res;
	// int		count = 0;

	// line = NULL;
	// res = "";
	// fd = open(cub->map, O_RDONLY);
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	res = ft_strfjoin(res, line, 3);
	// 	count++;
	// }
	// close(fd);
	// fclose(stdout);
	// printf("%s", res);
	cub->i = 1;
	return (NULL);
}