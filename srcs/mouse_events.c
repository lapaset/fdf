/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:38:29 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 14:28:55 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_warning(t_ptrs *ptrs, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < IMG_WIDTH)
		{
			mlx_pixel_put(ptrs->mlx_ptr, ptrs->win_ptr, j +
				((WIN_WIDTH - IMG_WIDTH) / 2), i + (WIN_HEIGHT - 30), 0x9A2D4C);
			j++;
		}
		i++;
	}
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr,
			WIN_WIDTH / 2 - (ft_strlen(str) * 5),
			WIN_HEIGHT - 25, WARNING_COLOR, str);
}

static void		ft_scroll_up(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply_z > 200)
	{
		ft_draw_warning(ptrs, "SCROLL MAX");
		return ;
	}
	if (ptrs->grid->multiply_z == -1)
		ptrs->grid->multiply_z = 1;
	else if (ptrs->grid->multiply_z < 0)
		ptrs->grid->multiply_z = -1 *
			ft_prev_fibonacci(ft_abs(ptrs->grid->multiply_z));
	else
		ptrs->grid->multiply_z = ft_next_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

static void		ft_scroll_down(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply_z < -200)
	{
		ft_draw_warning(ptrs, "SCROLL MIN");
		return ;
	}
	if (ptrs->grid->multiply_z == 1)
		ptrs->grid->multiply_z = -1;
	else if (ptrs->grid->multiply_z < 0)
		ptrs->grid->multiply_z = -1 *
			ft_next_fibonacci(ft_abs(ptrs->grid->multiply_z));
	else
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
