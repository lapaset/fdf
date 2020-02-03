/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colortest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:30 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:22:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//052866, 052866, 319367, 6CB25D, E0D4B5, FFFFFF
int		ft_theme_1_r(int nb)
{
	int		r[6];

	r[0] = 5;
	r[1] = 5;
	r[2] = 49;
	r[3] = 108;
	r[4] = 224;
	r[5] = 255;
	return (r[nb]);
}

int		ft_theme_1_g(int nb)
{
	int		g[6];

	g[0] = 40;
	g[1] = 40;
	g[2] = 147;
	g[3] = 178;
	g[4] = 212;
	g[5] = 255;
	return (g[nb]);
}
//052866, 105975, 319367, 6CB25D, E0D4B5, FFFFFF
int		ft_theme_1_b(int nb)
{
	int		b[6];

	b[0] = 102;
	b[1] = 117;
	b[2] = 103;
	b[3] = 93;
	b[4] = 181;
	b[5] = 255;
	return (b[nb]);
}

void	ft_color_theme_1(t_point *next, t_line *l, int max_z, int min_z)
{
	int		len;
	int		i;
	t_point temp_start;
	t_point temp_end;
	int		colorlimit;
	int		nb;

	i = ft_get_i(next, l);
	len = ft_get_len(l);
	colorlimit = (ft_abs(0 - max_z) + ft_abs(0 - min_z)) / 12;
	if (l->start->z < min_z + colorlimit)
		nb = 0;
	else if (l->start->z < min_z + 1 * colorlimit)
		nb = 1;
	else if (l->start->z < min_z + 2 * colorlimit)
		nb = 2;
	else if (l->start->z < min_z + 7 * colorlimit)
		nb = 3;
	else if (l->start->z < min_z + 10 * colorlimit)
		nb = 4;
	else
		nb = 5;
	temp_start.r = ft_theme_1_r(nb);
	temp_start.g = ft_theme_1_g(nb);
	temp_start.b = ft_theme_1_b(nb);
	if (l->end->z < min_z + colorlimit)
		nb = 0;
	else if (l->end->z < min_z + 1 * colorlimit)
		nb = 1;
	else if (l->end->z < min_z + 2 * colorlimit)
		nb = 2;
	else if (l->end->z < min_z + 7 * colorlimit)
		nb = 3;
	else if (l->end->z < min_z + 10 * colorlimit)
		nb = 4;
	else
		nb = 5;
	temp_end.r = ft_theme_1_r(nb);
	temp_end.g = ft_theme_1_g(nb);
	temp_end.b = ft_theme_1_b(nb);
	next->b = temp_start.b + (temp_end.b - temp_start.b) * i / len;
	next->r = temp_start.r + (temp_end.r - temp_start.r) * i / len;
	next->g = temp_start.g + (temp_end.g - temp_start.g) * i / len;
}