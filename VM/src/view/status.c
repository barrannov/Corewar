/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 00:14:37 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/03 14:43:56 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

static void	print_players(t_param *param, WINDOW *status)
{
	t_player *tmp;

	tmp = param->players;
	while (tmp)
	{
		wprintw(status, "\nPlayer %s\n", tmp->header->prog_name);
		wprintw(status, "Lives in period: %d", tmp->live_amount);
		tmp = tmp->next;
	}
}

void		print_status(t_param *param, WINDOW *status)
{
	wprintw(status, "cycle = %d\n", param->cycle);
	wprintw(status, "cycle_to_die = %d\n", param->cycle_to_die);
	wprintw(status, "amount_process = %d", param->amount_proc);
	print_players(param, status);
	wrefresh(status);
}
