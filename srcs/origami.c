/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origami.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:44:07 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 15:49:47 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_origami(t_grid *grid)
{
	grid->x0 = grid->center->dx - (grid->multiply *
				(grid->arr_width + grid->arr_height - 2)) / 2 +
				grid->multiply * (grid->arr_height - 1);
	grid->y0 = grid->center->dy - (grid->multiply *
				(grid->arr_width + grid->arr_height - 2)) / 4;
	
}

void	ft_get_draw_pts_origami(t_grid *grid, t_point *point)
{
	point->dx = grid->x0 + grid->multiply * (point->x - point->y);
	point->dy = grid->y0 + grid->multiply *
			((point->x + point->y) / 2) - grid->multiply_z * point->z;
}
