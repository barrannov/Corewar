/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:18:18 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:23:19 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if ((s - d) > 0)
	{
		while (len--)
			*d++ = *s++;
		return (dst);
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
		return (dst);
	}
	return (dst);
}
