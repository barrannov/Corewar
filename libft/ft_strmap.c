/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:21:47 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/28 19:00:16 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*map;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	map = (char *)malloc(len + 1);
	if (!map)
		return (NULL);
	while (*s)
		map[i++] = f(*s++);
	map[i] = '\0';
	return (map);
}
