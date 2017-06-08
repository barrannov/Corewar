/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 19:13:55 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/08 22:22:46 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

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

t_header		*header_init(t_param *par)
{
	t_header		*header;

	header = malloc(sizeof(t_header));
	ft_bzero(header, sizeof(t_header));
	header->magic = move_bits(COREWAR_EXEC_MAGIC);
	if (par->prog_name)
		ft_memmove(header->prog_name, par->prog_name,
				ft_strlen(par->prog_name));
	if (par->prog_comment)
		ft_memmove(header->comment, par->prog_comment,
				ft_strlen(par->prog_comment));
	header->prog_size = move_bits(par->prog_size);
	return (header);
}

void			writing_to_file(t_param *par, int fd)
{
	t_header		*header;
	void			*head_ptr;

	header = header_init(par);
	head_ptr = (void *)header;
	write(fd, head_ptr, sizeof(t_header));
	write_instructions(par, fd);
	free(header);
}

int				make_translation(char *name, t_param **par_lst)
{
	t_param			*par;
	int				fd;
	char			*file_name;

	if (is_valid_name(name))
	{
		file_name = get_file_name(name);
		fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG);
	}
	else
	{
		ft_putstr_fd("\e[91mInvalid file name!\n\e[39m", 2);
		return (0);
	}
	if (fd == -1)
		return (0);
	par = validation(name);
	set_arg_type_bytes(par);
	par->prog_size = set_oper_start_addr(par);
	set_label_value(par);
	writing_to_file(par, fd);
	close(fd);
	gv_function(par, par_lst, file_name);
	return (1);
}

int				main(int ac, char **av)
{
	int				index;
	t_param			*par_lst;

	par_lst = NULL;
	index = 1;
	if (ac <= 1)
	{
		ft_putstr_fd("usage: ./asm [src_file_1].s ", 2);
		ft_putstr_fd("[src_file_2].s ... [src_file_n].s\n", 2);
		return (1);
	}
	else
	{
		while (index < ac)
		{
			if (!make_translation(av[index++], &par_lst))
				return (1);
		}
	}
	return (0);
}
