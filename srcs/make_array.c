/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:38:09 by llahti            #+#    #+#             */
/*   Updated: 2020/02/12 09:33:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_add_color(char *input, int k, t_point *point, int last)
{
	if (input[k] == '-' || input[k] == '+')
		k++;
	if (!ft_isdigit(input[k]))
		ft_error("Error at ft_add_color, input lines not the same length", 1);
	while (ft_isdigit(input[k]))
		k++;
	if (input[k] == ',')
		k = ft_get_color(point, input, k, 0);
	else
		ft_get_default_color(point);
	if (k == -1 || (input[k] != ' ' && !last) ||
		(last && input[k] != '\0'))
		ft_error("Error at ft_add_color, input lines not the same length", 1);
	while (input[k] == ' ')
		k++;
	return (k);
}

static void	ft_add_coordinates(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

static void	ft_check_z_max_min(t_grid *grid, t_point *point)
{
	if (point->z > grid->max_z)
		grid->max_z = point->z;
	if (point->z < grid->min_z)
		grid->min_z = point->z;
}

void		ft_to_point_array(t_grid *grid, char **input)
{
	int		i;
	int		j;
	int		k;

	if (!(grid->arr = (t_point**)malloc(sizeof(t_point*) * grid->height)))
		ft_error("Malloc error at ft_to_point_array", 1);
	i = 0;
	while (i < grid->height)
	{
		if (!(grid->arr[i] = (t_point*)malloc(sizeof(t_point) * grid->width)))
			ft_error("Malloc error at ft_to_point_array", 1);
		j = 0;
		k = 0;
		while (input[i][k] == ' ')
			k++;
		while (j < grid->width)
		{
			ft_add_coordinates(&grid->arr[i][j], j, i, ft_atoi(&input[i][k]));
			ft_check_z_max_min(grid, &grid->arr[i][j]);
			k = ft_add_color(input[i], k, &grid->arr[i][j],
				j == grid->width - 1);
			j++;
		}
		i++;
	}
}
