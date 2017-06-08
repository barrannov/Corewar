/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oper_11_15.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:41:36 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:56:08 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

void	write_sti(int fd, char *code, int *i)
{
	int		arg2;
	int		arg3;

	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	arg3 = ((unsigned char)code[(*i) + 1] & 0x0c) >> 2;
	ft_putstr_fd("\tsti\t\t", fd);
	(*i) += 2;
	write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg2 == DIR_CODE)
		write_dir(fd, code, i, 2);
	else if (arg2 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg2 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg3 == DIR_CODE)
		write_dir(fd, code, i, 2);
	else if (arg3 == REG_CODE)
		write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_fork(int fd, char *code, int *i)
{
	ft_putstr_fd("\tfork\t", fd);
	(*i)++;
	write_dir(fd, code, i, 2);
	ft_putstr_fd("\n", fd);
}

void	write_lld(int fd, char *code, int *i)
{
	int		arg1;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	ft_putstr_fd("\tlld\t\t", fd);
	(*i) += 2;
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_lldi(int fd, char *code, int *i)
{
	int		arg1;
	int		arg2;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	ft_putstr_fd("\tlldi\t\t", fd);
	(*i) += 2;
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 2);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg2 == DIR_CODE)
		write_dir(fd, code, i, 2);
	else if (arg2 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_lfork(int fd, char *code, int *i)
{
	ft_putstr_fd("\tlfork\t\t", fd);
	(*i)++;
	write_dir(fd, code, i, 2);
	ft_putstr_fd("\n", fd);
}
