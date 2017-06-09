/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:47:44 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 16:47:06 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

static int		not_flag(char **argv, int n)
{
	if (!ft_strcmp(argv[n], "-d") || !ft_strcmp(argv[n], "-n") ||
			!ft_strcmp(argv[n], "-v"))
		return (0);
	else if (digit(argv[n]) && (!ft_strcmp(argv[n - 1], "-d") ||
				!ft_strcmp(argv[n - 1], "-n")))
		return (0);
	return (1);
}

static t_player	*get_player(int argc, char **argv)
{
	t_player	*player;
	t_player	*tmp;
	int			n;
	int			numb;

	n = 0;
	player = NULL;
	numb = 0;
	while (++n < argc)
	{
		if (not_flag(argv, n))
		{
			if (!player)
				player = read_file_vm(argv[n], vm_get_numb(argv, n, &numb));
			else
			{
				tmp = player;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = read_file_vm(argv[n], vm_get_numb(argv, n, &numb));
			}
		}
	}
	return (player);
}

void			check_flags_players(int argc, t_fl *flags, char **argv)
{
	if(flags->dump == 1)
		argc--;
	if(flags->vis == 1)
		argc--;
	if(!ft_strcmp(argv[1], "-n") || !ft_strcmp(argv[2], "-n") || !ft_strcmp(argv[3], "-n"))
		argc--;
	if(argc < 1)
		print_cant_read_source_file("");
}

int				main(int argc, char **argv)
{
	t_fl	*flags;

	flags = malloc(sizeof(t_fl));
	vm_get_flags(flags, argv);
	check_flags_players(argc - 1, flags, argv);
	if (argc == 1)
	{
		vm_print_usage();
		return (0);
	}
	logic(get_player(argc, argv), flags);
	return (0);
}
