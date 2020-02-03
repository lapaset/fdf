/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:34:37 by llahti            #+#    #+#             */
/*   Updated: 2020/02/03 17:32:44 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_down(t_ptrs *ptrs)
{
	ptrs->grid->center->dy -= ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
}

void	ft_move_up(t_ptrs *ptrs)
{
	ptrs->grid->center->dy += ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
}

void	ft_move_left(t_ptrs *ptrs)
{
	ptrs->grid->center->dx += ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
}

void	ft_move_right(t_ptrs *ptrs)
{
	ptrs->grid->center->dx -= ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
}

void	ft_reset_to_middle(t_ptrs *ptrs)
{
	ft_get_zero_point(ptrs->grid);
	ptrs->grid->center_moved = 0;
	ptrs->grid->center =
		&ptrs->grid->arr[ptrs->grid->arr_height / 2][ptrs->grid->arr_width / 2];
}
