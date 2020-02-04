/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:36:39 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 18:15:20 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reverse_arrows(t_ptrs *ptrs)
{
	if (ptrs->grid->reverse_arrows)
		ptrs->grid->reverse_arrows = 0;
	else
		ptrs->grid->reverse_arrows = 1;
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
	if (!ptrs->grid->center_moved)
		ft_get_zero_point(ptrs->grid);
}

void	ft_switch_color(t_ptrs *ptrs)
{
	if (ptrs->grid->colortheme == 0)
		ptrs->grid->colortheme = 1;
	else if (ptrs->grid->colortheme == 2)
		ptrs->grid->colortheme = 0;
	else
		ptrs->grid->colortheme++;
}
