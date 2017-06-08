/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:26:31 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:34:37 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*ptr;

	if (!num)
		return (memptr);
	ptr = memptr;
	while (num != 0)
	{
		*ptr++ = val;
		num--;
	}
	return (memptr);
}
