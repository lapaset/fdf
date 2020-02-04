/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:23:47 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 19:19:50 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fits_img(t_point *start, t_point *end)
{
	return ((start->dx >= 0 && start->dx < IMG_WIDTH) ||
			(start->dy >= 0 && start->dy < IMG_HEIGHT) ||
			(end->dx >= 0 && end->dx < IMG_WIDTH) ||
			(end->dy >= 0 && end->dy < IMG_HEIGHT));
}

void	ft_make_line(t_point *p1, t_point *p2, t_line *line)
{
	if ((p1->dx >= p2->dx && p1->dy > p2->dy) ||
		(p1->dx < p2->dx && p1->dy > p2->dy))
	{
		line->start = p2;
		line->end = p1;
	}
	else
	{
		line->start = p1;
		line->end = p2;
	}
	line->x0 = line->start->dx;
	line->x1 = line->end->dx;
	line->y0 = line->start->dy;
	line->y1 = line->end->dy;
}

void	ft_line_to_img(t_point *p1, t_point *p2, t_ptrs *ptrs)
{
	t_point	next;
	t_line	*line;
	int		done;

	ft_dot_to_image(p1, ptrs, 1);
	if (p1->dx == p2->dx && p1->dy == p2->dy)
		return ;
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		ft_error("Malloc error at ft_line_to_img", 1);
	ft_make_line(p1, p2, line);
	next.dx = line->x0;
	next.dy = line->y0;
	done = 0;
	while (!done)
	{
		done = ft_bresenham(line, &next);
		ft_get_dot_color(&next, line, ptrs->grid->colortheme != 0);
		ft_dot_to_image(&next, ptrs, 0);
	}
	free(line);

}

void	ft_grid_to_image(t_grid *grid, t_ptrs *ptrs)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->arr_height)
	{
		j = 0;
		while (j < grid->arr_width)
		{
			if (i + 1 < grid->arr_height &&
				ft_fits_img(&grid->arr[i][j], &grid->arr[i + 1][j]))
					ft_line_to_img(&grid->arr[i][j], &grid->arr[i + 1][j], ptrs);
			if (j + 1 < grid->arr_width &&
				ft_fits_img(&grid->arr[i][j], &grid->arr[i][j + 1]))
					ft_line_to_img(&grid->arr[i][j], &grid->arr[i][j + 1], ptrs);
			j++;
		}
		i++;
	}
}

void	ft_make_image(t_ptrs *ptrs, t_grid *grid)
{
	int		bpp;
	int		size_line;
	int		endian;

	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	ptrs->data_ptr = mlx_get_data_addr(ptrs->img_ptr, &bpp, &size_line,
						&endian);
	ft_grid_to_image(grid, ptrs);
}
