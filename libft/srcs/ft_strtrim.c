/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerdeka <akerdeka@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:24:47 by akerdeka          #+#    #+#             */
/*   Updated: 2020/07/15 08:07:21 by akerdeka         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_debut(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		mem1;

	i = 0;
	j = 0;
	mem1 = 0;
	while (set[i] != '\0' && s1[j] != '\0')
	{
		if (set[i] == s1[j])
		{
			j++;
			mem1 = j;
			i = -1;
		}
		i++;
	}
	return (mem1);
}

static int	ft_fin(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		mem2;

	i = 0;
	j = ft_strlen(s1) - 1;
	mem2 = ft_strlen(s1);
	while (set[i] != '\0' && j > 0)
	{
		if (set[i] == s1[j])
		{
			mem2 = j;
			j--;
			i = -1;
		}
		i++;
	}
	return (mem2);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		mem1;
	int		mem2;
	char	*res;

	i = 0;
	mem1 = ft_debut(s1, set);
	mem2 = ft_fin(s1, set);
	if (!(s1 && set))
		return (ft_strdup(""));
	if (mem1 > mem2)
		return (ft_strdup(""));
	if (!(res = (char *)malloc(sizeof(char) * (mem2 - mem1 + 1))))
		return (0);
	i = 0;
	while (mem1 < mem2)
	{
		res[i] = s1[mem1];
		mem1++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
