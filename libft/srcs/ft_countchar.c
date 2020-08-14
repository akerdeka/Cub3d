/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:47:41 by akerdeka          #+#    #+#             */
/*   Updated: 2020/08/11 12:00:41 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_countchar(char *str, char c)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret++;
		i++;
	}
	return (ret);
}