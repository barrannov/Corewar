/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_oper_6_10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:41:11 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:56:55 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

void	write_and(int fd, char *code, int *i)
{
	int				arg1;
	int				arg2;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	ft_putstr_fd("\tand\t\t", fd);
	(*i) += 2;
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_or(int fd, char *code, int *i)
{
	int				arg1;
	int				arg2;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	ft_putstr_fd("\tor\t\t", fd);
	(*i) += 2;
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_xor(int fd, char *code, int *i)
{
	int		arg1;
	int		arg2;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	ft_putstr_fd("\txor\t\t", fd);
	(*i) += 2;
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	if (arg1 == DIR_CODE)
		write_dir(fd, code, i, 4);
	else if (arg1 == IND_CODE)
		write_ind(fd, code, i);
	else if (arg1 == REG_CODE)
		write_reg(fd, code, i);
	ft_putchar_fd(SEPARATOR_CHAR, fd);
	ft_putchar_fd(' ', fd);
	write_reg(fd, code, i);
	ft_putstr_fd("\n", fd);
}

void	write_zjmp(int fd, char *code, int *i)
{
	ft_putstr_fd("\tzjmp\t", fd);
	(*i)++;
	write_dir(fd, code, i, 2);
	ft_putstr_fd("\n", fd);
}

void	write_ldi(int fd, char *code, int *i)
{
	int		arg1;
	int		arg2;

	arg1 = ((unsigned char)code[(*i) + 1] & 0xc0) >> 6;
	arg2 = ((unsigned char)code[(*i) + 1] & 0x30) >> 4;
	ft_putstr_fd("\tldi\t\t", fd);
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
