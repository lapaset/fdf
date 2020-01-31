/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:48:07 by llahti            #+#    #+#             */
/*   Updated: 2020/01/29 17:17:03 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_x_is_longer(t_line *l)
{
	return (ft_abs(l->x1 - l->x0) >= ft_abs(l->y1 - l->y0));
}

/*void	ft_bresenham(t_point *start, t_point *end, t_ptrs *ptrs, t_line *l)
{
	int			dx;
	int			dy;

	if (!ft_x_is_longer(l))
	{
		dy = l->y0;
		while (dy < l->y1)
		{
			dx = (dy - l->y0) * (l->x1 - l->x0) / (l->y1 - l->y0) + l->x0;
			ft_dot_to_image(dx, dy, ptrs, ft_get_dot_color(l->start, l->end, dy - l->y0, l->y1 - l->y0));
			dy++;
		}
		ft_dot_to_image(l->x1, l->y1, ptrs, ft_get_dot_color(l->start, l->end, dy, dy));
	}
	else if (l->x0 > l->x1 && ft_x_is_longer(l))
	{
		dx = l->x0;
		while (dx > l->x1)
		{
			dy = (l->x0 - dx) * (l->y1 - l->y0) / (l->x0 - l->x1) + l->y0;
			ft_dot_to_image(dx, dy, ptrs, ft_get_dot_color(start, end, dx - l->x0, l->x1 - l->x0));
			dx--;
		}
		ft_dot_to_image(l->x1, l->y1, ptrs, ft_get_dot_color(l->start, l->end, dx, dx));
	}
	else
	{
		dx = l->x0;
		while (dx < l->x1)
		{
			dy = (dx - l->x0) * (l->y1 - l->y0) / (l->x1 - l->x0) + l->y0;
			ft_dot_to_image(dx, dy, ptrs, ft_get_dot_color(l->start, l->end, dx - l->x0, l->x1 - l->x0));
			dx++;
		}
		ft_dot_to_image(l->x1, l->y1, ptrs, ft_get_dot_color(l->start, l->end, dx, dx));
	}
}*/

t_point		*ft_bresenham(t_line *l, t_point *next)
{
	if (!ft_x_is_longer(l))
	{
		next->dy = next->dy + 1;
		if (next->dy < l->y1)// && (l->y1 - l->y0) != 0)
			next->dx = (next->dy - l->y0) * (l->x1 - l->x0) / (l->y1 - l->y0) + l->x0;
		else
			next->dx = l->x1;
	}
	else if (l->x0 > l->x1 && ft_x_is_longer(l))
	{
		next->dx = next->dx - 1;
		if (next->dx > l->x1)// && (l->x0 - l->x1) != 0)
			next->dy = (l->x0 - next->dx) * (l->y1 - l->y0) / (l->x0 - l->x1) + l->y0;
		else
			next->dy = l->y1;
	}
	else
	{
		next->dx = next->dx + 1;
		if (next->dx < l->x1)// && (l->x1 - l->x0) != 0)
			next->dy = (next->dx - l->x0) * (l->y1 - l->y0) / (l->x1 - l->x0) + l->y0;
		else
			next->dy = l->y1;		
	}
	return (next);
}