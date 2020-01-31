/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:35:50 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 15:05:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//todo: count the zero point when map is first moved then zoomed
//      count the zero point when map is first moved then switched the projection
//		--->if you just saved the middle point and counted the y0 and x0 from that????
//also: leaks, destroying the image or erasing and drawing in the same image?

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

void	ft_key_funcs(void (*key_funcs[])(t_ptrs*), t_grid *grid)
{
	ft_bzero(key_funcs, sizeof(void*) * 126);
	key_funcs[53] = &ft_close;
	key_funcs[24] = &ft_zoom_in;
	key_funcs[69] = &ft_zoom_in;
	key_funcs[27] = &ft_zoom_out;
	key_funcs[78] = &ft_zoom_out;
	//key_funcs[8] = &ft_draw_image;
	key_funcs[15] = &ft_reverse_arrows;
	key_funcs[123] = &ft_move_right;
	key_funcs[124] = &ft_move_left;
	key_funcs[125] = &ft_move_up;
	key_funcs[126] = &ft_move_down;
	key_funcs[46] = &ft_reset_to_middle;
	key_funcs[35] = &ft_switch_projection;
	grid->key_funcs_set = 1;
}

int		ft_deal_key(int key, void *ptrs)
{
	t_ptrs	*temp;
	void	(*key_funcs[127])(t_ptrs*);

	temp = (t_ptrs*)ptrs;
	ft_key_funcs(key_funcs, temp->grid);
	if (key >= 123 && key <= 126 && temp->grid->reverse_arrows)
		key = ft_get_reverse_key(key);
	if (key_funcs[key] != 0)
		key_funcs[key](ptrs);
	ft_reset_image(ptrs);
	return (key);
}
