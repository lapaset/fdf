/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origami.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:44:07 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:29:54 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_origami(t_grid *grid)
{
	if (!grid->center_moved)
	{
		grid->center->dx = IMG_WIDTH / 2;
		grid->center->dy = IMG_HEIGHT / 2;
	}

	grid->x0 = grid->center->dx - (grid->multiply *
				(grid->arr_width + grid->arr_height - 2)) / 2 +
				grid->multiply * (grid->arr_height - 1);
	grid->y0 = grid->center->dy - (grid->multiply *
				(grid->arr_width + grid->arr_height - 2)) / 4;
	
}

void	ft_get_draw_pts_origami(t_grid *grid)
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
			point->dx = grid->x0 + grid->multiply * (point->x - point->y);
			point->dy = grid->y0 + grid->multiply *
					((point->x + point->y) / 2) - grid->multiply_z * point->z;
			j++;
		}
		i++;
	}
}
