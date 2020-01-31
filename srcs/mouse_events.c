/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:38:29 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 14:12:12 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_scroll_up(t_ptrs *ptrs)
{
	ptrs->grid->multiply_z = ft_next_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

static void		ft_scroll_down(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply_z < 2)
		return ;
	ptrs->grid->multiply_z = ft_prev_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

int				ft_deal_mouse(int button, int x, int y, void *ptrs)
{
	t_ptrs	*temp;

	temp = ptrs;
	ft_printf("button: %d, %d,%d\n", button, x, y);
	if (button == 5)
		ft_scroll_up(temp);
	if (button == 4)
		ft_scroll_down(temp);
	return (button);
}
