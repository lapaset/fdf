/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:48:07 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 15:04:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_x_is_longer(t_line *l)
{
	return (ft_abs(l->x1 - l->x0) >= ft_abs(l->y1 - l->y0));
}

static int	ft_is_the_end(t_line *l, t_point *next)
{
	if (ft_x_is_longer(l))
	{
		if (l->x0 > l->x1)
			next->dx = next->dx - 1;
		else
			next->dx = next->dx + 1;
		if (next->dx != l->x1)
			return (0);
		next->dy = l->y1;
		return (1);
	}
	next->dy = next->dy + 1;
	if (next->dy != l->y1)
		return (0);
	next->dx = l->x1;
	return (1);
}

int			ft_bresenham(t_line *l, t_point *next)
{
	if (ft_is_the_end(l, next))
		return (1);
	if (ft_x_is_longer(l))
		next->dy = ft_abs(l->x0 - next->dx) * (l->y1 - l->y0) /
					ft_abs(l->x0 - l->x1) + l->y0;
	else
		next->dx = (next->dy - l->y0) * (l->x1 - l->x0) /
					(l->y1 - l->y0) + l->x0;
	return (0);
}
