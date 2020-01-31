/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:34:37 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 12:46:44 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_down(t_ptrs *ptrs)
{
	ptrs->grid->y0 -= ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
}

void	ft_move_up(t_ptrs *ptrs)
{
	ptrs->grid->y0 += ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
}

void	ft_move_left(t_ptrs *ptrs)
{
	ptrs->grid->x0 += ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
}

void	ft_move_right(t_ptrs *ptrs)
{
	ptrs->grid->x0 -= ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
}

void	ft_reverse_arrows(t_ptrs *ptrs)
{
	if (ptrs->grid->reverse_arrows)
		ptrs->grid->reverse_arrows = 0;
	else
		ptrs->grid->reverse_arrows = 1;	
}
