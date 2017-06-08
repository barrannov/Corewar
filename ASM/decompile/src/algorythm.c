/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algirithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:49:28 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:52:04 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

static void	write_name(int fd, char *name)
{
	ft_putstr_fd(NAME_CMD_STRING, fd);
	ft_putstr_fd("\t\t\"", fd);
	ft_putstr_fd(name, fd);
	ft_putstr_fd("\"\n", fd);
}

static void	write_comment(int fd, char *comment)
{
	ft_putstr_fd(COMMENT_CMD_STRING, fd);
	ft_putstr_fd("\t\"", fd);
	ft_putstr_fd(comment, fd);
	ft_putstr_fd("\"\n\n", fd);
}

static void	write_commands(int fd, char *code, int code_len)
{
	int			i;
	static void	(*fc_array[16])(int, char *, int *) = { write_live,
		write_ld, write_st, write_add, write_sub, write_and, write_or,
		write_xor, write_zjmp, write_ldi, write_sti, write_fork,
		write_lld, write_lldi, write_lfork, write_aff };

	i = 0;
	while (i < code_len)
	{
		if (code[i] >= 1 && code[i] <= 16)
		{
			(*fc_array[code[i] - 1])(fd, code, &i);
		}
		else
		{
			i++;
		}
	}
}

void		write_algorythm(char *cor_name, t_header *header,
		char *code, int prog_len)
{
	int			fd;
	char		*file_name;

	file_name = get_file_name(cor_name);
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRWXU | S_IRWXG | S_IRWXO);
	write_name(fd, header->prog_name);
	write_comment(fd, header->comment);
	write_commands(fd, code, prog_len);
	free(file_name);
	close(fd);
}
