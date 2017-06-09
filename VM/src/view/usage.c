/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:23 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 19:38:44 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void				print_error_players(void)
{
	ft_putstr_fd("Too many champions\n", 2);
	exit(1);
}

void				print_size_error(char *name)
{
	ft_putstr_fd("Player ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" is too big for this machine\n", 2);
	exit(1);
}

/*
** prints usage
*/

void				vm_print_usage(void)
{
	ft_putstr("Usage: ./corewar [-d N -v] <[-n N]champion1.cor> <[-n N]...>\n"
			"    -d N      : Dumps memory after N cycles then exits\n"
			"                If all battle is less than N cycles, \n"
			"                programm will display the last cycle\n"
			"    -n N      : Means that Player after this flag will be \n"
			"                Player number N. If there is no -n flag,\n"
			"                the next available number will be given to \n"
			"                Player, starting from 1 \n"
			"    -v        : Visualisation option\n");
	exit(1);
}

/*
**	displays an error "Can't read source file <file_name>"
**	function takes <file_name>
*/

void				print_cant_read_source_file(char *name)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void				dump_error(void)
{
	ft_putstr_fd("Incorrect value for -d, cycle must be greater than 0\n", 2);
	exit(1);
}
