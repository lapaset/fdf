/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:16:00 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 11:23:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_draw_points(t_grid *grid)
{
	void	(*projections[4])(t_grid*);

	projections[0] = &ft_get_draw_pts_paralinear;
	projections[1] = &ft_get_draw_pts_isometric;
	projections[2] = &ft_get_draw_pts_origami;
	projections[3] = &ft_get_draw_pts_flat;
	projections[grid->projection](grid);
}

void	ft_get_zero_point(t_grid *grid)
{
	void 	(*zeropoints[4])(t_grid*);

	zeropoints[0] = &ft_get_zero_paralinear;
	zeropoints[1] = &ft_get_zero_isometric;
	zeropoints[2] = &ft_get_zero_origami;
	zeropoints[3] = &ft_get_zero_flat;
	zeropoints[grid->projection](grid);
}

int		ft_draw_image(t_ptrs *ptrs)
{
	if (!ptrs->grid->zero_moved)
		ft_get_zero_point(ptrs->grid);
	ft_get_draw_points(ptrs->grid);
	ft_make_image(ptrs, ptrs->grid);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr,
				(WIN_WIDTH - IMG_WIDTH) / 2, (WIN_HEIGHT - IMG_HEIGHT) /2);
	return (1);
}

int     ft_draw(t_grid *grid)
{
	t_ptrs	*ptrs;

	if (!(ptrs = (t_ptrs*)malloc(sizeof(t_ptrs))))
		return (ft_error("Malloc error at ft_draw", 1));
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
					"le window");
	ptrs->grid = grid;
	ft_draw_image(ptrs);
	mlx_key_hook(ptrs->win_ptr, ft_deal_key, (void*)ptrs);
	mlx_mouse_hook(ptrs->win_ptr, ft_deal_mouse, (void*)ptrs);
	mlx_loop(ptrs->mlx_ptr);
	return (1);
}
