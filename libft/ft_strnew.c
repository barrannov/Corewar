/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:39:58 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:32:37 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (i <= size)
		ptr[i++] = '\0';
	return (ptr);
}
