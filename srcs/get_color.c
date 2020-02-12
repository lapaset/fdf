/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:02:15 by llahti            #+#    #+#             */
/*   Updated: 2020/02/12 10:35:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_rgb(char *input, int len, int minlen)
{
	int		temp;
	int		res;

	if (len < minlen)
		return (0);
	res = ft_hexa_to_int(input[len - minlen + 1]);
	temp = ft_hexa_to_int(input[len - minlen]);
	return (res + temp * 16);
}

void		ft_get_default_color(t_point *point)
{
	point->b = DEFAULT_BLUE;
	point->g = DEFAULT_GREEN;
	point->r = DEFAULT_RED;
}

int			ft_get_color(t_point *point, char *input, int k, int theme)
{
	int		colorlen;

	if (!(ft_strnequ(&input[k], ",0x", 3) ||
			ft_strnequ(&input[k], ",0X", 3)))
		ft_error("Error at ft_get_color, no color after comma", 1);
	k += 3;
	colorlen = ft_hexa_len(&input[k]);
	if (theme)
	{
		point->tb = ft_get_rgb(&input[k], colorlen, 2);
		point->tg = ft_get_rgb(&input[k], colorlen, 4);
		point->tr = ft_get_rgb(&input[k], colorlen, 6);
		return (1);
	}
	point->b = ft_get_rgb(&input[k], colorlen, 2);
	point->g = ft_get_rgb(&input[k], colorlen, 4);
	point->r = ft_get_rgb(&input[k], colorlen, 6);
	k += colorlen;
	return (k);
}
