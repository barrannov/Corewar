/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oper_1_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:41:00 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:56:34 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

void	write_live(int fd, char *code, int *i)
{
	ft_putstr_fd("\tlive\t", fd);
	(*i)++;
	write_dir(fd, code, i, 4);
	ft_putstr_fd("\n", fd);
}

void	write_ld(int fd, char *code, int *i)
{
	unsigned char	code_byte;
	char			arg1;

	code_byte = code[(*i) + 1];
	arg1 = (code_byte & 0xc0) >> 6;
	(*i) += 2;
	ft_putstr_fd("\tld\t\t", fd);
	if (arg1 == DIR_CODE)
	{
		write_dir(fd, code, i, 4);
	}
	else if (arg1 == IND_CODE)
	{
		write_ind(fd, code, i);
	}
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_st(int fd, char *code, int *i)
{
	unsigned char	code_byte;
	int				arg2;

	code_byte = code[(*i) + 1];
	arg2 = (code_byte & 0x30) >> 4;
	(*i) += 2;
	ft_putstr_fd("\tst\t\t", fd);
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg2 == IND_CODE)
	{
		write_ind(fd, code, i);
	}
	else if (arg2 == REG_CODE)
	{
		write_reg(fd, code, i);
	}
	ft_putstr_fd("\n", fd);
}

void	write_add(int fd, char *code, int *i)
{
	ft_putstr_fd("\tadd\t\t", fd);
	(*i) += 2;
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_sub(int fd, char *code, int *i)
{
	ft_putstr_fd("\tsub\t\t", fd);
	(*i) += 2;
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}
