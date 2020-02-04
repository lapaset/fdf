/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:47:31 by llahti            #+#    #+#             */
/*   Updated: 2020/02/04 14:48:07 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int pow)
{
	int		temp;
	int		i;

	if (pow == 0)
		return (1);
	temp = nb;
	i = 1;
	while (i < pow)
	{
		nb *= temp;
		i++;
	}
	return (nb);
}
