/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:43:34 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 11:13:59 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	ft_iterate_arr(t_ptrs *ptrs, void (f)(t_point*, t_ptrs*))
{
	int		i;
	int		j;

	i = 0;
	while (i < ptrs->grid->arr_height)
	{
		j = 0;
		while (j < ptrs->grid->arr_width)
		{
			f(&ptrs->grid->arr[i][j], ptrs);
			j++;
		}
		i++;
	}
}*/

/*void	ft_iterate_arr(t_grid *grid, void (f)(t_point*))
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->arr_height)
	{
		j = 0;
		while (j < grid->arr_width)
		{
			ft_printf("%d,%d\n", i, j);
			f(&grid->arr[i][j]);
			j++;
		}
		i++;
	}
}*/

/*void 	ft_print_arr(t_point **arr, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%d,%d,%d,%d,%d ", arr[i][j].x, arr[i][j].y, arr[i][j].z,
			arr[i][j].dx, arr[i][j].dy);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}*/

int		ft_usage()
{
	ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	exit(1);
}

int		ft_error(char *str, int nb)
{
	perror(str);
	exit(nb);
}
