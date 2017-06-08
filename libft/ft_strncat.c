/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:59:22 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:27:53 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (n-- && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
