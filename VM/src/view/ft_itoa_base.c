/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 20:06:59 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 22:27:42 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/view.h"

int		count_string(int value, int base)
{
	int result;

	result = 0;
	while (value >= base)
	{
		value = value / base;
		result++;
	}
	result++;
	return (result);
}

char	*ft_itoa_for_minus(int value, int base)
{
	char	*str;
	char	*all_bases;
	int		m;

	all_bases = "0123456789abcdef";
	if (value == -2147483648)
		str = "-2147483648";
	else
	{
		value = -value;
		m = count_string(value, base) + 1;
		str = (char *)malloc(sizeof(char) * m + 1);
		str[m] = '\0';
		while (value >= base)
		{
			str[--m] = all_bases[value % base];
			value = value / base;
		}
		str[--m] = all_bases[value];
		str[--m] = '-';
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	char	*all_bases;
	char	*str;
	int		m;

	all_bases = "0123456789abcdef";
	if (value < 0 && base == 10)
		str = ft_itoa_for_minus(value, base);
	else
	{
		if (value < 0)
			value = -value;
		m = count_string(value, base);
		str = (char *)malloc(sizeof(char) * m + 1);
		str[m] = '\0';
		while (value >= base)
		{
			str[--m] = all_bases[value % base];
			value = value / base;
		}
		str[--m] = all_bases[value];
	}
	return (str);
}
