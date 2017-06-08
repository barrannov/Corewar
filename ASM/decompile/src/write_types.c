/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:47:00 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:57:29 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

void	write_dir(int fd, char *code, int *i, int flag)
{
	ft_putchar_fd(DIRECT_CHAR, fd);
	if (flag == 4)
	{
		ft_putnbr_fd(get_int_value(code, *i), fd);
		(*i) += 4;
	}
	else if (flag == 2)
	{
		ft_putnbr_fd(get_short_value(code, *i), fd);
		(*i) += 2;
	}
}

void	write_reg(int fd, char *code, int *i)
{
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(code[*i], fd);
	(*i)++;
}

void	write_ind(int fd, char *code, int *i)
{
	ft_putnbr_fd(get_short_value(code, *i), fd);
	(*i) += 2;
}

void	write_aff(int fd, char *code, int *i)
{
	ft_putstr_fd("\taff\t\t", fd);
	(*i)++;
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}
