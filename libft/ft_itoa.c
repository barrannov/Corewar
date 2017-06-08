/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:35:15 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/28 18:32:07 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_len(int nb)
{
	unsigned int	i;
	int				dup;

	dup = nb;
	i = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	nb = (nb < 0) ? -nb : nb;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	i = (dup < 0) ? i + 1 : i;
	return (i);
}

char			*ft_itoa(int nb)
{
	char			*line;
	int				len;
	int				write;
	unsigned int	dup;

	dup = nb;
	len = int_len(nb);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	dup = (nb < 0) ? -nb : nb;
	line[len--] = '\0';
	while (len >= 0)
	{
		write = dup % 10;
		line[len--] = write + '0';
		dup /= 10;
	}
	if (nb < 0)
		line[0] = '-';
	return (line);
}
