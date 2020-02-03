/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:47:59 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:29:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_flat(t_grid *grid)
{
	if (!grid->center_moved)
	{
		grid->center->dx = IMG_WIDTH / 2;
		grid->center->dy = IMG_HEIGHT / 2;
	}
	grid->x0 = grid->center->dx - grid->multiply * (grid->arr_width - 1) / 2;
	grid->y0 = grid->center->dy - grid->multiply * (grid->arr_height - 1) / 2;
}

void	ft_get_draw_pts_flat(t_grid *grid)
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
			point->dx = grid->x0 + grid->multiply * point->x;
			point->dy = grid->y0 + grid->multiply * (point->y) -
							grid->multiply_z * point->z;
			j++;
		}
		i++;
	}
}
