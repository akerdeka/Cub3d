/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_percent.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <akerdeka@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:20:06 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 17:04:17 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*percent_converter(void)
{
	char	*value;

	if (!(value = malloc(sizeof(char) * 2)))
		return (NULL);
	value[0] = '%';
	value[1] = '\0';
	return (value);
}
