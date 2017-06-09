/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:53:51 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/09 14:49:26 by abaranov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void				unset_is_alive_process(t_processor *proc)
{
	t_processor *live_proc;

	live_proc = proc;
	while (live_proc)
	{
		live_proc->is_alive = 0;
		live_proc = live_proc->next;
	}
}

void				unset_live_amount(t_param *param)
{
	t_player *live_proc;

	live_proc = param->players;
	while (live_proc)
	{
		live_proc->live_amount = 0;
		live_proc = live_proc->next;
	}
}

void				print_winner(int numb, char *name)
{
	ft_putstr("Player ");
	ft_putnbr(numb);
	ft_putstr(" (");
	ft_putstr(name);
	ft_putstr(") won\n");
}

void				output_the_winner(t_player *players)
{
	t_player *temp_player;

	temp_player = players;
	if (amount_lst_el_players(players) == 1)
		print_winner(temp_player->numb, temp_player->header->prog_name);
	else
	{
		while (temp_player)
		{
			if (temp_player->live == 1)
			{
				print_winner(temp_player->numb, temp_player->header->prog_name);
				return ;
			}
			temp_player = temp_player->next;
		}
		print_winner(players->numb, players->header->prog_name);
	}
}
