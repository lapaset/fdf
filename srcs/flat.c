/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:47:59 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 18:25:06 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_flat(t_grid *grid)
{
	grid->x0 = grid->center->dx - grid->multiply * (grid->arr_width - 1) / 2;
	grid->y0 = grid->center->dy - grid->multiply * (grid->arr_height - 1) / 2;
}

int		ft_get_draw_pts_flat(t_grid *grid, t_point *point)
{
	point->dx = grid->x0 + grid->multiply * point->x;
	point->dy = grid->y0 + grid->multiply * (point->y) - grid->multiply_z *
				point->z;
	return (1);
}
