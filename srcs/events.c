/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:35:50 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 11:48:49 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//todo: count the zero point when map is first moved then zoomed
//also: leaks, destroying the image or erasing and drawing in the same image?

void	ft_reset_image(t_ptrs *ptrs)
{
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	ft_draw_image(ptrs);
}

void	ft_zoom_in(t_ptrs *ptrs)
{
	ptrs->grid->multiply = ft_next_fibonacci(ptrs->grid->multiply);
}

void	ft_zoom_out(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply < 2)
		return;
	ptrs->grid->multiply = ft_prev_fibonacci(ptrs->grid->multiply);
	ft_printf("multiply: %d, projection: %d\n", ptrs->grid->multiply, ptrs->grid->multiply);
}

void	ft_switch_projection(t_ptrs *ptrs)
{
	if (ptrs->grid->projection == 3)
		ptrs->grid->projection = 0;
	else
		ptrs->grid->projection++;
	ft_printf("multiply: %d, projection: %d\n", ptrs->grid->multiply, ptrs->grid->multiply);
	ft_draw_image(ptrs);
}

void	ft_move_down(t_ptrs *ptrs)
{
	ptrs->grid->y0 -= ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
	ft_draw_image(ptrs);
}

void	ft_move_up(t_ptrs *ptrs)
{
	ptrs->grid->y0 += ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
	ft_draw_image(ptrs);
}

void	ft_move_left(t_ptrs *ptrs)
{
	ptrs->grid->x0 += ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
	ft_draw_image(ptrs);
}

void	ft_move_right(t_ptrs *ptrs)
{
	ptrs->grid->x0 -= ptrs->grid->multiply * 2;
	ptrs->grid->zero_moved = 1;
	ft_draw_image(ptrs);
}

void	ft_reverse_scroll(t_ptrs *ptrs)
{
	if (ptrs->grid->reverse_arrows)
		ptrs->grid->reverse_arrows = 0;
	else
		ptrs->grid->reverse_arrows = 1;	
}

void	ft_reset_to_middle(t_ptrs *ptrs)
{
	ft_get_zero_point(ptrs->grid);
	ptrs->grid->zero_moved = 0;
	ft_draw_image(ptrs);
}

void	ft_close(t_ptrs *ptrs)
{
	//ft_free(ptrs->grid);
	//free(ptrs->data_ptr);<this did not work
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	//free(ptrs->mlx_ptr);
	//free(ptrs->grid);<this makes you lose more stuff so theres something in the grid to be freed??
	exit(1);
}

/*void	*ft_key_funcs(t_ptrs *ptrs)
{
	void	(*key_funcs[126])(t_ptrs*);

	ft_bzero(key_funcs, sizeof(void*) * 126);
	key_funcs[53] = &ft_close;
	key_funcs[24] = &ft_zoom_in;
	key_funcs[69] = &ft_zoom_in;
	key_funcs[27] = &ft_zoom_out;
	key_funcs[78] = &ft_zoom_out;
	//key_funcs[8] = &ft_draw_image;
}*/

int		ft_deal_key(int key, void *ptrs)
{
	t_ptrs 	*temp;

	temp = (t_ptrs*)ptrs;
	if (key == 53)
		ft_close(temp);
	if (key == 69 || key == 24)
		ft_zoom_in(temp);
	if (key == 27 || key == 78)
		ft_zoom_out(temp);
	if (key == 4)
		mlx_string_put(temp->mlx_ptr, temp->win_ptr, 1000, 500, 0xff00ff, "Hello world");
	if (key == 8)
		ft_draw_image(temp);
	if (key == 35)
		ft_switch_projection(temp);
	if ((key == 124 && temp->grid->reverse_arrows == 0) || (key == 123 && temp->grid->reverse_arrows == 1))
		ft_move_left(temp);
	if ((key == 123 && temp->grid->reverse_arrows == 0) || (key == 124 && temp->grid->reverse_arrows == 1))
		ft_move_right(temp);
	if ((key == 126 && temp->grid->reverse_arrows == 0) || (key == 125 && temp->grid->reverse_arrows == 1))
		ft_move_down(temp);
	if ((key == 125 && temp->grid->reverse_arrows == 0) || (key == 126 && temp->grid->reverse_arrows == 1))
		ft_move_up(temp);
	if (key == 15)
		ft_reverse_scroll(temp);
	if (key == 46)
		ft_reset_to_middle(temp);
	return (key);
}

void	ft_scroll_up(t_ptrs *ptrs)
{
	ptrs->grid->multiply_z = ft_next_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

void	ft_scroll_down(t_ptrs *ptrs)
{
	if (ptrs->grid->multiply_z < 2)
		return ;
	ptrs->grid->multiply_z = ft_prev_fibonacci(ptrs->grid->multiply_z);
	ft_draw_image(ptrs);
}

int		ft_deal_mouse(int button, int x, int y, void *ptrs)
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
