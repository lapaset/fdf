/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorthemes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:30 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 18:13:18 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*theme_1[11] = {"10", ",0x203760", ",0x0088BF", ",0xAEDCA7",
	",0x1A6F38", ",0x1F7518", ",0x487A15", ",0x787F12", ",0x855A0F",
	",0xBBA681", ",0xF1F2F3"};

char	*theme_2[11] = {"10", ",0xF2EE16", ",0x95ED13", ",0x36E710",
	",0x0DE142", ",0x0BDB97", ",0x08C2D6", ",0x0667D0", ",0x040FCA",
	",0x4901C4", ",0x9600BF"};

char	**themes[2] = {theme_1, theme_2};
//todo tomorrow:
//	-refactor
//	-make different color models
//	-try filling?
//	-consider the rotating stuff

void	ft_get_theme_colors(t_grid *grid, t_point *point)
{
	int		steps;
	int		part;
	char	**theme;

	steps = ft_atoi(theme_1[0]);
	part = (steps - 1) * (point->z - grid->min_z) / (grid->max_z - grid->min_z);
	theme = themes[grid->colortheme - 1];
	ft_get_color(point, theme[part + 1], 0, 1);
	if (grid->colortheme)
		return ;
}