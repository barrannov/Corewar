/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:22:43 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/06 15:38:02 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = dst;
	if (n == 0)
		return (dst);
	while (n)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		n--;
	}
	return (ptr);
}
