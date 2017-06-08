/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:50:04 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:34:07 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
	int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return (++dst);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	return (NULL);
}
