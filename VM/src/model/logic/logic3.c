/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 23:00:07 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/08 20:32:21 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static	void		help_command(t_processor *process, t_param *param)
{
	if (process->temp_command == 8)
		handle_xor(param, process);
	else if (process->temp_command == 9)
		handle_zjmp(param, process);
	else if (process->temp_command == 10)
		handle_ldi(param, process);
	else if (process->temp_command == 11)
		handle_sti(param, process);
	else if (process->temp_command == 12)
		handle_fork(param, process);
	else if (process->temp_command == 13)
		handle_lld(param, process);
	else if (process->temp_command == 14)
		handle_lldi(param, process);
	else if (process->temp_command == 15)
		handle_lfork(param, process);
	else if (process->temp_command == 16)
		handle_aff(param, process);
	else
		process->pc = (process->pc + 1) % MEM_SIZE;
}

void				execute_command(t_processor *process, t_param *param)
{
	if (process->waite_cycles != 0)
		return ;
	if (process->temp_command == 1)
		handle_live(param, process);
	else if (process->temp_command == 2)
		handle_ld(param, process);
	else if (process->temp_command == 3)
		handle_st(param, process);
	else if (process->temp_command == 4)
		handle_add(param, process);
	else if (process->temp_command == 5)
		handle_sub(param, process);
	else if (process->temp_command == 6)
		handle_and(param, process);
	else if (process->temp_command == 7)
		handle_or(param, process);
	else
		help_command(process, param);
}

static	void		help_set(t_processor *process)
{
	if (process->temp_command == 9)
		process->waite_cycles = 20;
	else if (process->temp_command == 10)
		process->waite_cycles = 25;
	else if (process->temp_command == 11)
		process->waite_cycles = 25;
	else if (process->temp_command == 12)
		process->waite_cycles = 800;
	else if (process->temp_command == 13)
		process->waite_cycles = 10;
	else if (process->temp_command == 14)
		process->waite_cycles = 50;
	else if (process->temp_command == 15)
		process->waite_cycles = 1000;
	else if (process->temp_command == 16)
		process->waite_cycles = 2;
}

void				set_command_for_proc(t_processor *process, t_param *param)
{
	if (process->waite_cycles != 0)
		return ;
	process->temp_command = param->map[process->pc];
	if (process->temp_command == 1)
	{
		process->is_alive++;
		process->waite_cycles = 10;
	}
	else if (process->temp_command == 2)
		process->waite_cycles = 5;
	else if (process->temp_command == 3)
		process->waite_cycles = 5;
	else if (process->temp_command == 4)
		process->waite_cycles = 10;
	else if (process->temp_command == 5)
		process->waite_cycles = 10;
	else if (process->temp_command == 6)
		process->waite_cycles = 6;
	else if (process->temp_command == 7)
		process->waite_cycles = 6;
	else if (process->temp_command == 8)
		process->waite_cycles = 6;
	else
		help_set(process);
}
