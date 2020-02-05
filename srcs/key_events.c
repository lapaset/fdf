/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:35:50 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 11:41:56 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(t_ptrs *ptrs)
{
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	exit(1);
}

void	ft_reset_image(t_ptrs *ptrs)
{
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	ft_draw_image(ptrs);
}

int		ft_get_reverse_key(int key)
{
	if (key == 123 || key == 125)
		return (key + 1);
	return (key - 1);
}

void	ft_key_funcs(int (*key_funcs[])(t_ptrs*))
{
	ft_bzero(key_funcs, sizeof(void*) * 126);
	key_funcs[53] = &ft_close;
	key_funcs[24] = &ft_zoom_in;
	key_funcs[69] = &ft_zoom_in;
	key_funcs[27] = &ft_zoom_out;
	key_funcs[78] = &ft_zoom_out;
	key_funcs[15] = &ft_reverse_arrows;
	key_funcs[123] = &ft_move_right;
	key_funcs[124] = &ft_move_left;
	key_funcs[125] = &ft_move_up;
	key_funcs[126] = &ft_move_down;
	key_funcs[46] = &ft_reset_to_middle;
	key_funcs[35] = &ft_switch_projection;
	key_funcs[8] = &ft_switch_color;
}

int		ft_deal_key(int key, void *ptrs)
{
	t_ptrs	*temp;
	int		(*key_funcs[127])(t_ptrs*);

	ft_printf("key pressed %d\n", key);
	if (key > 126)
		return (0);
	temp = (t_ptrs*)ptrs;
	ft_key_funcs(key_funcs);
	if (key >= 123 && key <= 126 && temp->grid->reverse_arrows)
		key = ft_get_reverse_key(key);
	if (key_funcs[key] != 0)
	{
		if (key_funcs[key](ptrs))
			ft_reset_image(ptrs);
	}
	return (key);
}
