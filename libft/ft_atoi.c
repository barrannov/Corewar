/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:56:08 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:30:49 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		negativ;
	int		number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}
