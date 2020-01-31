/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:38:09 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 09:28:40 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_add_color(char *input, int k, t_point *point, int last)
{
	if (input[k] == '-' || input[k] == '+')
		k++;
	while (ft_isdigit(input[k]))
		k++;
	if (input[k] == ',')
		k = ft_get_color(point, input, k);
	else
		ft_get_default_color(point);
	if (k == -1 || (input[k] != ' ' && !last))
		ft_error("Error at ft_add_color, no space", 1);
	if (last && input[k] != '\0')
		ft_error("Error at ft_add_color, no eol", 1);
	while (input[k] == ' ')
		k++;
	return (k);
}

void	ft_to_point_array(t_grid *grid, char **input)
{
	int 	i;
	int		j;
	int		k;

	if (!(grid->arr = (t_point**)malloc(sizeof(t_point*) * grid->arr_height)))
		ft_error("Malloc error at ft_to_point_array", 1);
	i = 0;
	while (i < grid->arr_height)
	{
		if (!(grid->arr[i] = (t_point*)malloc(sizeof(t_point) * grid->arr_width)))
			ft_error("Malloc error at ft_to_point_array", 1);
		j = 0;
		k = 0;
		while (input[i][k] == ' ')
			k++;
		while (j < grid->arr_width)
		{
			grid->arr[i][j].x = j;
			grid->arr[i][j].y = i;
			grid->arr[i][j].z = ft_atoi(&input[i][k]);
			k = ft_add_color(input[i], k, &grid->arr[i][j], j == grid->arr_width - 1);
			j++;
		}
		i++;
	}
}