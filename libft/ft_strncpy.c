/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:56:46 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:27:16 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*ptr;

	ptr = dest;
	if (*src == '\0')
	{
		while (n--)
			*dest++ = '\0';
		return (dest);
	}
	while (*src && n)
	{
		*dest++ = *src++;
		n--;
	}
	while (n-- > 0)
		*dest++ = '\0';
	return (ptr);
}
