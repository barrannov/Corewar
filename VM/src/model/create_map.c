/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:29:15 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 19:31:20 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

static void	check_players(t_player *players)
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
	if (res > MAX_PLAYERS)
		print_error_players();
}

void		add_to_map(t_player *players, t_param *params, int pc)
{
	int i;

	i = 0;
	while (i < (int)players->header->prog_size)
	{
		params->map[pc] = players->commands[i];
		params->map_c[pc] = (unsigned char)players->vis_numb;
		pc++;
		i++;
	}
}

void		create_map(t_player *players, t_param *param)
{
	t_player	*temp_players;
	int			pc;

	pc = 0;
	check_players(players);
	temp_players = players;
	param->players = players;
	param->map = (unsigned char *)ft_strnew(MEM_SIZE);
	param->map_c = (unsigned char *)ft_strnew(MEM_SIZE);
	while (temp_players)
	{
		add_to_map(temp_players, param, pc);
		temp_players->pos = pc;
		temp_players->live = 0;
		temp_players->live_amount = 0;
		temp_players = temp_players->next;
		pc += MEM_SIZE / param->amount_champs;
	}
}
