/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:14:40 by llahti            #+#    #+#             */
/*   Updated: 2020/01/31 14:11:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int		ft_next_fibonacci(int nb)
{
	int		res;
	int		prev;
	int		temp;

	if (nb == 1)
		return (2);
	prev = 2;
	res = 3;
	while (prev < nb)
	{
		temp = res;
		res = prev + res;
		prev = temp;
	}
	return (res);
}

int		ft_prev_fibonacci(int nb)
{
	int		res;
	int		prev;
	int		temp;

	if (nb < 3)
		return (1);
	prev = 1;
	res = 2;
	while (res < nb)
	{
		temp = res;
		res = prev + res;
		prev = temp;
	}
	return (prev);
}
