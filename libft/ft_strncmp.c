/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:52:14 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:30:30 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((!*s1 && !*s2) || !n)
		return (0);
	if (*s1 == *s2)
	{
		while ((*s1 == *s2) && --n && *s1 && *s2)
		{
			s1++;
			s2++;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
