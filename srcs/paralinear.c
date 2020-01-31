/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paralinear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 12:48:53 by llahti            #+#    #+#             */
/*   Updated: 2020/01/29 18:13:48 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zero_paralinear(t_grid *grid)
{
	grid->x0 = (IMG_WIDTH - grid->multiply * (grid->arr_width + grid->arr_height - 2)) /
			2 + grid->multiply * (grid->arr_height - 1);
	grid->y0 = (IMG_HEIGHT - grid->multiply * (grid->arr_width + grid->arr_height - 2)) / 2;
}

void	ft_get_draw_pts_paralinear(t_grid *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->arr_height)
	{
		j = 0;
		while (j < grid->arr_width)
		{
			grid->arr[i][j].dx = grid->x0 + grid->multiply * (grid->arr[i][j].x - 
									grid->arr[i][j].y);
			grid->arr[i][j].dy = grid->y0 + grid->multiply * (grid->arr[i][j].x +
									grid->arr[i][j].y) - grid->multiply_z * grid->arr[i][j].z;
			j++;
		}
		i++;
	}
}
