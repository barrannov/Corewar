/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:52:25 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/01 15:57:24 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		result;

	result = 0;
	while ((result * result) != nb)
	{
		if ((result * result) > nb)
			return (0);
		result++;
	}
	return (result);
}
