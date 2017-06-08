/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:41:30 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/26 21:56:45 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*find;
	int		i;
	int		j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			find = (char *)&big[i];
			while (big[i++] == little[j++])
				if (!little[j])
					return (find);
			i -= j;
		}
		i++;
	}
	return (NULL);
}
