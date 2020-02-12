/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:43:34 by llahti            #+#    #+#             */
/*   Updated: 2020/02/12 09:27:58 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename>");
	exit(1);
}

int		ft_error(char *str, int nb)
{
	perror(str);
	exit(nb);
}
