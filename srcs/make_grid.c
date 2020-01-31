/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:45:45 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 11:25:36 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_arr_width(char *line)
{
	int 	width;

	if (!line)
		return (0);
	while (*line == ' ')
		line++;
	width = 1;
	while (*line != '\0')
	{
		if (*line == ' ')
		{
			width++;
			while (*line == ' ')
				line++;
		}
		else
			line++;
	}
	return (width);
}

void	ft_get_projection_and_zoom(t_grid *grid)
{
	grid->projection = DEFAULT_PROJECTION;
	grid->multiply = 1 + IMG_WIDTH / (grid->arr_width + grid->arr_height);
}

void 	ft_make_grid(t_grid **grid, char **lines, int height)
{
	if (!(*grid = (t_grid*)malloc(sizeof(t_grid))))
		ft_error("Malloc error at ft_make_grid", 1);
	(*grid)->arr_width = ft_count_arr_width(lines[0]);
	(*grid)->arr_height = height;
	(*grid)->reverse_arrows = 0;
	(*grid)->zero_moved = 0;
	(*grid)->multiply_z = 1;
	ft_get_projection_and_zoom(*grid);
	//ft_printf("arr size: %d,%d, multiply: %d\n", (*grid)->arr_width, height, (*grid)->multiply);
	ft_to_point_array(*grid, lines);
}
