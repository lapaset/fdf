/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:38:29 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 11:46:31 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_warning_box(t_ptrs *ptrs)
{
	int		i;
	int		j;

	i = 0;
	while (i < 35)
	{
		j = 0;
		while (j < 160)
		{
			mlx_pixel_put(ptrs->mlx_ptr, ptrs->win_ptr, j +
				(WIN_WIDTH / 2 - 80), i + (WIN_HEIGHT - 55), 0x9A2D4C);
			j++;
		}
		i++;
	}
}

static void		ft_scroll_up(t_ptrs *ptrs)
{
	ptrs->grid->multiply_z = ft_next_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

static void		ft_scroll_down(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply_z < 2)
	{
		ft_draw_warning_box(ptrs);
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, WIN_WIDTH / 2 - 70,
			WIN_HEIGHT - 50, WARNING_COLOR, "MAXIMUM SCROLL");
		return ;
	}
	ptrs->grid->multiply_z = ft_prev_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

int				ft_deal_mouse(int button, int x, int y, void *ptrs)
{
	t_ptrs	*temp;

	(void)x;
	(void)y;
	temp = ptrs;
	if (button == 5)
		ft_scroll_up(temp);
	if (button == 4)
		ft_scroll_down(temp);
	return (button);
}
