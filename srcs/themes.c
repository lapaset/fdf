/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   themes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:37:33 by llahti            #+#    #+#             */
/*   Updated: 2020/02/05 12:51:30 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_theme_1(void)
{
	char **theme;

	theme = (char**)malloc(sizeof(char*) * 11 + 10 * 10 + 3);
	theme[0] = "10";
	theme[1] = ",0x203760";
	theme[2] = ",0x0088BF";
	theme[3] = ",0x00755F";
	theme[4] = ",0x0B4C3D";
	theme[5] = ",0x18925D";
	theme[6] = ",0x684F4B";
	theme[7] = ",0x4C3732";
	theme[8] = ",0x422E27";
	theme[9] = ",0xBBA681";
	theme[10] = ",0xF1F2F3";
	return (theme);
}

char	**ft_theme_2(void)
{
	char **theme;

	theme = (char**)malloc(sizeof(char*) * 11 + 10 * 10 + 3);
	theme[0] = "10";
	theme[1] = ",0xF2EE16";
	theme[2] = ",0x95ED13";
	theme[3] = ",0x36E710";
	theme[4] = ",0x0DE142";
	theme[5] = ",0x0BDB97";
	theme[6] = ",0x08C2D6";
	theme[7] = ",0x0667D0";
	theme[8] = ",0x040FCA";
	theme[9] = ",0xB896CA";
	theme[10] = ",0x9600BF";
	return (theme);
}

char	**ft_theme_3(void)
{
	char **theme;

	theme = (char**)malloc(sizeof(char*) * 7 + 6 * 10 + 2);
	theme[0] = "6";
	theme[1] = ",0x9B01F2";
	theme[2] = ",0xD95AFE";
	theme[3] = ",0xE3DDEF";
	theme[4] = ",0xB896CA";
	theme[5] = ",0x151219";
	theme[6] = ",0x6F7691";
	return (theme);
}

char	**ft_theme_4(void)
{
	char **theme;

	theme = (char**)malloc(sizeof(char*) * 6 + 5 * 10 + 2);
	theme[0] = "5";
	theme[1] = ",0xFFB345";
	theme[2] = ",0xFF705E";
	theme[3] = ",0xFF406F";
	theme[4] = ",0x283A63";
	theme[5] = ",0x273149";
	return (theme);
}
