/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:39:32 by llahti            #+#    #+#             */
/*   Updated: 2020/01/29 18:12:47 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_isometric(t_grid *grid)
{
	t_point p;
	int		y;

	p = grid->arr[grid->arr_height - 1][grid->arr_width - 1];
	y = grid->multiply * (p.x + p.y);
	grid->y0 = ((IMG_HEIGHT - y) / 2);
	grid->x0 = ((IMG_WIDTH - sqrt(3) * y) / 2 + sqrt(3) * y *
			grid->arr_height / (grid->arr_height + grid->arr_width));
}

void	ft_get_draw_pts_isometric(t_grid *grid)
{
	int		i;
	int		j;
	t_point *point;

	i = 0;
	while (i < grid->arr_height)
	{
		j = 0;
		while (j < grid->arr_width)
		{
			point = &grid->arr[i][j];
			point->dy = grid->y0 + grid->multiply * (point->y + point->x);
			point->dx = grid->x0 + sqrt(3) * ((y0 + grid->multiply * 2 *
						point->x) - y0) - sqrt(3) * (point->dy - grid->y0);
			point->dy -= grid->multiply_z * point->z;
			j++;
		}
		i++;
	}
}
