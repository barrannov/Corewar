/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:30:40 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/28 19:01:17 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*map;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	map = (char *)malloc(len + 1);
	if (!map)
		return (NULL);
	while (*s)
	{
		map[i] = f(i, *s++);
		i++;
	}
	map[i] = '\0';
	return (map);
}
