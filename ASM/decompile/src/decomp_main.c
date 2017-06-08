/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decomp_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:00:09 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/03 17:59:07 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompiler.h"

t_header	*header_init(int fd)
{
	t_header	*header;

	header = (t_header *)malloc(sizeof(t_header));
	if (fd == -1)
	{
		ft_putstr_fd("Error: File doesn't exist\n", ERROR_STREAM);
		return (NULL);
	}
	read(fd, (char *)header, sizeof(t_header));
	return (header);
}

int			main(int ac, char **av)
{
	t_header	*header;
	int			fd;
	int			prog_len;
	char		*code;

	if (ac > 2 || ac == 1)
	{
		ft_putstr_fd("usage: ./decompiler [src_file].cor\n", ERROR_STREAM);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (!(header = header_init(fd)))
			return (1);
		prog_len = move_bits(header->prog_size);
		code = (char *)malloc(prog_len);
		read(fd, code, prog_len);
		if (!check_header(header, fd))
			return (1);
		close(fd);
		write_algorythm(av[1], header, code, prog_len);
	}
	return (0);
}
