/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:48:41 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:41:12 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*find;
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[i] || ft_strequ(big, little))
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			find = (char *)&big[i];
			while (big[i++] == little[j++])
			{
				if (i > len)
					return (NULL);
				if (!little[j])
					return (find);
			}
			i -= j;
		}
		i++;
	}
	return (NULL);
}
