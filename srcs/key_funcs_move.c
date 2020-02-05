/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:34:37 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 11:10:30 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_move_down(t_ptrs *ptrs)
{
	ptrs->grid->center->dy -= ptrs->grid->multiply * 2;
	return (1);
}

int		ft_move_up(t_ptrs *ptrs)
{
	ptrs->grid->center->dy += ptrs->grid->multiply * 2;
	return (1);
}

int		ft_move_left(t_ptrs *ptrs)
{
	ptrs->grid->center->dx += ptrs->grid->multiply * 2;
	return (1);
}

int		ft_move_right(t_ptrs *ptrs)
{
	ptrs->grid->center->dx -= ptrs->grid->multiply * 2;
	return (1);
}

int		ft_reset_to_middle(t_ptrs *ptrs)
{
	ft_get_zero_point(ptrs->grid);
	ptrs->grid->center->dx = IMG_WIDTH / 2;
	ptrs->grid->center->dy = IMG_HEIGHT / 2;
	return (1);
}
