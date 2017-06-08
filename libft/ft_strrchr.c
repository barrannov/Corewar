/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:32:26 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:29:00 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;
	char	*tmp;

	tmp = (char*)s;
	find = NULL;
	while (*tmp)
	{
		if (*tmp == (char)c)
			find = tmp;
		tmp++;
	}
	if (!*tmp && !c)
		return (tmp);
	else
		return (find);
}
