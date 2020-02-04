/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:20:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 17:11:39 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_len(t_line *l)
{
	if (ft_x_is_longer(l))
		return (l->x1 - l->x0);
	else
		return (l->y1 - l->y0);
}

int		ft_get_i(t_point *next, t_line *l)
{
	if (ft_x_is_longer(l))
		return (next->dx - l->x0);
	else
		return (next->dy - l->y0);
}

void	ft_get_dot_color_theme(t_point *next, t_line *l, int len, int i)
{
	if (len == 0)
	{
		next->b = l->start->tb;
		next->g = l->start->tg;
		next->r = l->start->tr;
		return ;
	}
	next->b = l->start->tb + (l->end->tb - l->start->tb) * i / len;
	next->r = l->start->tr + (l->end->tr - l->start->tr) * i / len;
	next->g = l->start->tg + (l->end->tg - l->start->tg) * i / len;
}

void	ft_get_dot_color(t_point *next, t_line *l, int theme)
{
	int		len;
	int		i;

	i = ft_get_i(next, l);
	len = ft_get_len(l);

	if (theme)
	{
		ft_get_dot_color_theme(next, l, len, i);
		return ;
	}
	if (len == 0)
	{
		next->b = l->start->b;
		next->g = l->start->g;
		next->r = l->start->r;
		return ;
	}
	next->b = l->start->b + (l->end->b - l->start->b) * i / len;
	next->r = l->start->r + (l->end->r - l->start->r) * i / len;
	next->g = l->start->g + (l->end->g - l->start->g) * i / len;
}

void	ft_dot_to_image(t_point *dot, t_ptrs *ptrs, int single)
{
	int start_i;

	if (dot->dx < 0 || dot->dx > IMG_WIDTH - 1 ||
		dot->dy < 0 || dot->dy > IMG_HEIGHT - 1)
		return ;
	start_i = dot->dx * 4 + 4 * IMG_WIDTH * dot->dy;
	if (single && ptrs->grid->colortheme != 0)
	{
		ptrs->data_ptr[start_i] = mlx_get_color_value(ptrs->mlx_ptr, dot->tb);
		ptrs->data_ptr[start_i + 1] = mlx_get_color_value(ptrs->mlx_ptr, dot->tg);
		ptrs->data_ptr[start_i + 2] = mlx_get_color_value(ptrs->mlx_ptr, dot->tr);
		return ;
	}
	ptrs->data_ptr[start_i] = mlx_get_color_value(ptrs->mlx_ptr, dot->b);
	ptrs->data_ptr[start_i + 1] = mlx_get_color_value(ptrs->mlx_ptr, dot->g);
	ptrs->data_ptr[start_i + 2] = mlx_get_color_value(ptrs->mlx_ptr, dot->r);
}
