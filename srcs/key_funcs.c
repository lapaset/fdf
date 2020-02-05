/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:36:39 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 14:24:09 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_reverse_arrows(t_ptrs *ptrs)
{
	if (ptrs->grid->reverse_arrows)
		ptrs->grid->reverse_arrows = 0;
	else
		ptrs->grid->reverse_arrows = 1;
	return (0);
}

int		ft_zoom_in(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply > 400)
	{
		ft_draw_warning(ptrs, "ZOOM MAX");
		return (0);
	}
	ptrs->grid->multiply = ft_next_fibonacci(ptrs->grid->multiply);
	return (1);
}

int		ft_zoom_out(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply < 2)
	{
		ft_draw_warning(ptrs, "ZOOM MIN");
		return (0);
	}
	ptrs->grid->multiply = ft_prev_fibonacci(ptrs->grid->multiply);
	return (1);
}

int		ft_switch_projection(t_ptrs *ptrs)
{
	if (ptrs->grid->projection == 3)
		ptrs->grid->projection = 0;
	else
		ptrs->grid->projection++;
	return (1);
}

int		ft_switch_color(t_ptrs *ptrs)
{
	if (ptrs->grid->colortheme == THEMES)
		ptrs->grid->colortheme = 0;
	else
		ptrs->grid->colortheme++;
	return (1);
}
