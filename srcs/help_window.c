/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:51:14 by llahti            #+#    #+#             */
/*   Updated: 2020/01/28 16:39:40 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../xpm/test_win.xpm"

void		ft_make_help_window(t_ptrs *ptrs)
{
    int     width;
    int     height;

    ptrs->help = mlx_xpm_to_image(ptrs->mlx_ptr, teapot_xpm, &width, &height);
    mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->help, 20, 20);
    //mlx_loop(ptrs->mlx_ptr);
}