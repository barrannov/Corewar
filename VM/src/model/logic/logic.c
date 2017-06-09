/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:17:51 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 19:10:16 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void				special_for_denchik(t_param *params, t_fl *flags)
{
	t_processor *temp_proc;

	temp_proc = params->processors;
	while (temp_proc)
	{
		if (params->cycle == flags->dump && params->cycle > 0)
		{
			print_map(params->map);
			exit(1);
		}
		set_command_for_proc(temp_proc, params);
		execute_process(temp_proc, params);
		temp_proc = temp_proc->next;
	}
	if (params->cycle % params->cycle_to_die == 0 && params->cycle > 0)
	{
		handle_check(params);
		unset_is_alive_process(params->processors);
		unset_live_amount(params);
	}
}

void				algorithm(t_param *params, t_fl *flags)
{
	params->cycle = 0;
	while (params->cycle_to_die > 0 && params->amount_proc > 0)
	{
		if (flags->vis == 1)
			visualize(params);
		special_for_denchik(params, flags);
		params->cycle++;
	}
	if (flags->vis == 1)
		endwin();
	if (params->cycle < flags->dump)
		print_map(params->map);
	output_the_winner(params->players);
}

void				logic(t_player *players, t_fl *flags)
{
	t_param *param;

	param = malloc(sizeof(t_param));
	param->processors = NULL;
	param->amount_champs = count_champs(players);
	create_map(players, param);
	get_processes(param);
	param->amount_proc = amount_lst_el(param->processors);
	param->amount_champs = 0;
	flags->vis == 1 ? (param->print_live = 0) :
		(param->print_live = 1);
	param->cycle_to_die = CYCLE_TO_DIE;
	algorithm(param, flags);
	vm_free_all(param);
}
