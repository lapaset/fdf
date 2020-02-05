/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorthemes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:30 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 13:59:34 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**ft_themes(int nb)
{
	char	**(*themes[THEMES])(void);

	themes[0] = &ft_theme_1;
	themes[1] = &ft_theme_2;
	themes[2] = &ft_theme_3;
	themes[3] = &ft_theme_4;
	return (themes[nb - 1]());
}

void		ft_get_theme_colors(t_grid *grid, t_point *point)
{
	int		steps;
	int		color;
	char	**theme;

	theme = ft_themes(grid->colortheme);
	steps = ft_atoi(theme[0]);
	if (grid->max_z - grid->min_z == 0)
	{
		ft_get_color(point, theme[1], 0, 1);
		return ;
	}
	if (point->z == grid->min_z || (point->z < 0 &&
		point->z < ((grid->min_z - 0) / 2)))
		color = 1;
	else if (point->z == grid->min_z + 2 || point->z < 0)
		color = 2;
	else
		color = (steps - 3) * (point->z - 0) / (grid->max_z - 0) + 3;
	ft_get_color(point, theme[color], 0, 1);
	free(theme);
}
