/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:12:00 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/05 20:23:43 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
	return (tmp);
}
