/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:39:32 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 19:05:16 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_isometric(t_grid *grid)
{
	grid->y0 = grid->center->dy - (grid->multiply *
				(grid->arr_width + grid->arr_height - 2) / 2);
	grid->x0 = grid->center->dx - sqrt(3) * (grid->multiply *
				(grid->arr_width + grid->arr_height - 2) / 2) +
				grid->multiply * sqrt(3) * (grid->arr_height - 1);
}

int		ft_get_draw_pts_isometric(t_grid *grid, t_point *point)
{
	point->dy = grid->y0 + grid->multiply * (point->y + point->x);
	point->dx = grid->x0 + sqrt(3) * ((y0 + grid->multiply * 2 *
				point->x) - y0) - sqrt(3) * (point->dy - grid->y0);
	point->dy -= grid->multiply_z * point->z;
	/*if ((ft_fits_img(point, &grid->arr[point->y - 1][point->x])) ||
		(ft_fits_img(point, &grid->arr[point->y + 1][point->x])) ||
		(ft_fits_img(point, &grid->arr[point->y][point->x - 1])) ||
		(ft_fits_img(point, &grid->arr[point->y][point->x - 1])))*/
		return (1);
	return (0);
}
