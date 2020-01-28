/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 11:28:09 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 11:26:10 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*temp;

	temp = s;
	while (n != 0)
	{
		if ((char)*temp == c)
			return ((char *)temp);
		n--;
		temp++;
	}
	return (0);
}
