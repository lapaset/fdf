/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:47:59 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 11:58:08 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_flat(t_grid *grid)
{
	grid->x0 = grid->center->dx - grid->multiply * (grid->width - 1) / 2;
	grid->y0 = grid->center->dy - grid->multiply * (grid->height - 1) / 2;
}

void	ft_get_draw_pts_flat(t_grid *grid, t_point *point)
{
	point->dx = grid->x0 + grid->multiply * point->x;
	point->dy = grid->y0 + grid->multiply * (point->y) - grid->multiply_z *
				point->z;
}
