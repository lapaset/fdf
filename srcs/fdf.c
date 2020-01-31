/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:03:50 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 09:29:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_read(char ***input, char **argv)
{
	int		fd;
	int		height;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("Error at ft_read", 1);
	height = 0;
	while (get_next_line(fd, &(*input)[height]) == 1)
		height++;
	close(fd);
	return (height);
}

int		main(int arg, char **argv)
{
	t_grid	*grid;
	char    **input;
	int     height;

	if (arg != 2)
		return (ft_usage());
	if (!(input = (char**)malloc(sizeof(char*) * MAX_SIZE)))
		ft_error("Malloc error at main", 1);
	if ((height = ft_read(&input, argv)) == -1)
		ft_error("Error at read", 1);
	if (height == 0)
		ft_error("Error at main, empty file", 1);
	grid = NULL;
	ft_make_grid(&grid, input, height);
	ft_draw(grid);
	return (0);
}
