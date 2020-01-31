/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:36:39 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 14:12:32 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset_to_middle(t_ptrs *ptrs)
{
	ft_get_zero_point(ptrs->grid);
	ptrs->grid->zero_moved = 0;
}

void	ft_close(t_ptrs *ptrs)
{
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	exit(1);
}

void	ft_zoom_in(t_ptrs *ptrs)
{
	ptrs->grid->multiply = ft_next_fibonacci(ptrs->grid->multiply);
}

void	ft_zoom_out(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply < 2)
		return ;
	ptrs->grid->multiply = ft_prev_fibonacci(ptrs->grid->multiply);
}

void	ft_switch_projection(t_ptrs *ptrs)
{
	if (ptrs->grid->projection == 3)
		ptrs->grid->projection = 0;
	else
		ptrs->grid->projection++;
	if (!ptrs->grid->zero_moved)
		ft_get_zero_point(ptrs->grid);
}
