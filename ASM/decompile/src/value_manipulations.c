/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:48:09 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:55:01 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

int				check_header(t_header *header, int fd)
{
	char	buff[4];
	size_t	size;

	if (move_bits(header->magic) != COREWAR_EXEC_MAGIC)
	{
		ft_putstr_fd("Error: Wrong execution code\n", 2);
		return (0);
	}
	else if (ft_strlen(header->prog_name) > PROG_NAME_LENGTH)
	{
		ft_putstr_fd("Error: Too long prog name\n", 2);
		return (0);
	}
	else if (ft_strlen(header->comment) > COMMENT_LENGTH)
	{
		ft_putstr_fd("Error: Too long prog comment\n", 2);
		return (0);
	}
	else if ((size = read(fd, buff, 1)) != 0)
	{
		ft_putstr_fd("Error: Programm code is bigger than indicated\n", 2);
		return (0);
	}
	else
		return (1);
}

int				get_int_value(char *code, int iter)
{
	int		*value;
	char	*swap_ptr;
	char	tmp;

	value = (int *)&code[iter];
	swap_ptr = &code[iter];
	tmp = swap_ptr[0];
	swap_ptr[0] = swap_ptr[3];
	swap_ptr[3] = tmp;
	tmp = swap_ptr[1];
	swap_ptr[1] = swap_ptr[2];
	swap_ptr[2] = tmp;
	return (*value);
}

short			get_short_value(char *code, int iter)
{
	short	*value;
	char	*swap_ptr;
	char	tmp;

	value = (short *)&code[iter];
	swap_ptr = &code[iter];
	tmp = swap_ptr[0];
	swap_ptr[0] = swap_ptr[1];
	swap_ptr[1] = tmp;
	return (*value);
}

char			*get_file_name(char *cor_name)
{
	char	*s_name;
	int		name_len;

	if (!cor_name)
		return (NULL);
	name_len = ft_strlen(cor_name) - 2;
	s_name = (char*)malloc(name_len + 1);
	ft_bzero(s_name, name_len + 1);
	ft_memmove(s_name, cor_name, name_len);
	ft_memmove(s_name + name_len - 2, ".s", 2);
	return (s_name);
}

unsigned int	move_bits(unsigned int num)
{
	unsigned int	fs;
	unsigned int	s;
	unsigned int	t;
	unsigned int	fo;

	fs = num >> 24;
	s = (num << 8) >> 24;
	t = (num << 16) >> 24;
	fo = (num << 24) >> 24;
	num = (fo << 24) + (t << 16) + (s << 8) + fs;
	return (num);
}
