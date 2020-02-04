/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:34:37 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 19:24:24 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_move_down(t_ptrs *ptrs)
{
	ptrs->grid->center->dy -= ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
	return (1);
}

int		ft_move_up(t_ptrs *ptrs)
{
	ptrs->grid->center->dy += ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
	return (1);
}

int		ft_move_left(t_ptrs *ptrs)
{
	ptrs->grid->center->dx += ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
	return (1);
}

int		ft_move_right(t_ptrs *ptrs)
{
	ptrs->grid->center->dx -= ptrs->grid->multiply * 2;
	ptrs->grid->center_moved = 1;
	return (1);
}

int		ft_reset_to_middle(t_ptrs *ptrs)
{
	ft_get_zero_point(ptrs->grid);
	ptrs->grid->center_moved = 0;
	ptrs->grid->center->dx =
		ptrs->grid->arr[ptrs->grid->arr_height / 2][ptrs->grid->arr_width / 2].dx;
	ptrs->grid->center->dy =
		ptrs->grid->arr[ptrs->grid->arr_height / 2][ptrs->grid->arr_width / 2].dy;
	return (1);
}
