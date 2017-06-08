/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:04:49 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/06 15:39:37 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*tmp;

	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	tmp = sub;
	while (start--)
		s++;
	while (len--)
		*tmp++ = *s++;
	*tmp = '\0';
	return (sub);
}
