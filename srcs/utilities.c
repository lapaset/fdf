/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:43:34 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 14:10:11 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	exit(1);
}

int		ft_error(char *str, int nb)
{
	perror(str);
	exit(nb);
}
