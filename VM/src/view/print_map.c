/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 21:21:28 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/06 23:07:20 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/view.h"

static void	print_hex(unsigned char hex)
{
	if (hex == 0)
		ft_putstr("00 ");
	else if (hex < 16)
	{
		ft_putstr("0");
		ft_putstr(ft_itoa_base(hex, 16));
		ft_putstr(" ");
	}
	else
	{
		ft_putstr(ft_itoa_base(hex, 16));
		ft_putstr(" ");
	}
}

void		print_map(unsigned char *map)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			ft_putstr("\n");
			ft_putstr(" # ");
		}
		print_hex(map[i]);
	}
	ft_putstr("\n");
}
