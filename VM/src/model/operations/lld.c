/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:20:57 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:37:36 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void	load_value(t_param *param, t_processor *proc, unsigned int value)
{
	if (param->map[(proc->pc + 6) % MEM_SIZE] > 0 &&
			param->map[(proc->pc + 6) % MEM_SIZE] < REG_NUMBER)
	{
		value == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
		proc->reg[param->map[(proc->pc + 6) % MEM_SIZE] - 1] = value;
		proc->pc = (proc->pc + 7) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}

void		handle_lld(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	if (val->val1 == 2)
		arg = handle_dir(params, proc, 4, 2);
	else if (val->val1 == 3)
		arg = handle_ind(params, proc, 2, 13);
	else
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		return ;
	}
	load_value(params, proc, arg);
	free(val);
}
