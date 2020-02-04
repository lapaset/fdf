/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorthemes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:32:30 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 20:00:20 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*theme_1[11] = {"10", ",0x203760", ",0x0088BF", ",0xAEDCA7",
	",0x1A6F38", ",0x1F7518", ",0x487A15", ",0x787F12", ",0x855A0F",
	",0xBBA681", ",0xF1F2F3"};

char	*theme_2[11] = {"10", ",0xF2EE16", ",0x95ED13", ",0x36E710",
	",0x0DE142", ",0x0BDB97", ",0x08C2D6", ",0x0667D0", ",0x040FCA",
	",0x4901C4", ",0x9600BF"};

/*char	*theme_3[7] = {"6", ",0xCCE1F2", ",0xC6F8E5", ",0xFBF7D5",
	",0xF9DED7", ",0xF5CDDE", ",0xE2BEF1"};*/
char	*theme_3[7] = {"6", ",0x9B01F2", ",0xD95AFE", ",0xE3DDEF",
	",0xB896CA", ",0x151219", ",0x6F7691"};

char	*theme_4[6] = {"5", ",0xFFB345", ",0xFF705E", ",0xFF406F",
	",0x283A63", ",0x273149"};
/*char	*theme_4[7] = {"6", ",0x0B4C3D", ",0x00755F", ",0x18925D",
	",0x684F4B", ",0x4C3732", ",0x422E27"};*/

char	**themes[THEMES] = {theme_1, theme_2, theme_3, theme_4};
//todo tomorrow:
//	-refactor
//	-make different color models
//	-try filling?
//	-consider the rotating stuff

void	ft_get_theme_colors(t_grid *grid, t_point *point)
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
}