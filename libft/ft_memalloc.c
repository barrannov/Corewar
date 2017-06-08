/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:17:03 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:40:10 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return ((void *)ptr);
}
