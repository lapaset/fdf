/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:39:32 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:30:05 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_isometric(t_grid *grid)
{
	int		y;

	if (!grid->center_moved)
	{
		grid->center->dx = IMG_WIDTH / 2;
		grid->center->dy = IMG_HEIGHT / 2;
	}
	y = grid->multiply * (grid->arr_width + grid->arr_height - 2);
	grid->y0 = grid->center->dy - (y / 2);
	grid->x0 = grid->center->dx - sqrt(3) * (y / 2) + grid->multiply * sqrt(3) *
				(grid->arr_height - 1);
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
