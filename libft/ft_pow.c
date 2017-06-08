/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:42:14 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/01 15:55:54 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int power)
{
	int		result;

	result = nb;
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (--power > 0)
		result *= nb;
	return (result);
}
