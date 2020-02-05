/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorthemes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:30 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 10:39:32 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "themes.h"

//todo tomorrow:
//	-should the themes be put in fuctions or files so they would
//		not be global variables?
//	-add string instructions
//	-go through all the files to see that they pass the norm
//	-rm all the ft_printf stuff
//	-check the leaks
//
//	Leave for the future:
//	-make all the drawing functions work from middle out
//	-try filling?
//	-consider the rotating stuff

/*void	ft_get_theme_colors(t_grid *grid, t_point *point)
{
	int		steps;
	int		color;
	char	**theme;

	theme = themes[grid->colortheme - 1];
	steps = ft_atoi(theme[0]);
	if (grid->max_z - grid->min_z == 0)
		color = 1;
	else
		color = (steps - 1) * (point->z - grid->min_z) /
				(grid->max_z - grid->min_z) + 1;
	ft_get_color(point, theme[color], 0, 1);
}*/

void	ft_get_theme_colors(t_grid *grid, t_point *point)
{
	int		steps;
	int		color;
	char	**theme;

	theme = themes[grid->colortheme - 1];
	steps = ft_atoi(theme[0]);
	if (grid->max_z - grid->min_z == 0)
	{
		ft_get_color(point, theme[1], 0, 1);
		return ;
	}
	if (point->z == grid->min_z || (point->z < 0 && point->z < ((grid->min_z - 0) / 2)))
		color = 1;
	else if (point->z == grid->min_z + 2 || point->z < 0)
		color = 2;
	else
		color = (steps - 3) * (point->z - 0) / (grid->max_z - 0) + 3;
	ft_get_color(point, theme[color], 0, 1);
}