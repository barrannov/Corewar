/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:55:06 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/08 21:07:48 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

int		amount_lst_el_players(t_player *player)
{
	int	i;

	i = 0;
	while (player)
	{
		i++;
		player = player->next;
	}
	return (i);
}

int		amount_lst_el(t_processor *procs)
{
	int i;

	i = 0;
	while (procs)
	{
		i++;
		procs = procs->next;
	}
	return (i);
}

void	execute_process(t_processor *process, t_param *param)
{
	if (process->waite_cycles > 0)
	{
		process->waite_cycles--;
		if (process->waite_cycles > 0)
			return ;
	}
	execute_command(process, param);
}

int		count_champs(t_player *players)
{
	int			res;
	t_player	*tmp;

	res = 0;
	tmp = players;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}
