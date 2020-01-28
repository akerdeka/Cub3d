/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:12:45 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 14:25:20 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*temp1;
	unsigned const char	*temp2;

	i = 0;
	temp1 = (unsigned const char	*)s1;
	temp2 = (unsigned const char	*)s2;
	if (n <= 0)
		return (0);
	while (*temp1 == *temp2 && i < (n - 1))
	{
		temp1++;
		temp2++;
		i++;
	}
	return (*temp1 - *temp2);
}
