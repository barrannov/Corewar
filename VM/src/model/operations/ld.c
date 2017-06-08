/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:50:05 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:31:56 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void	load_value(t_param *param, t_processor *proc, unsigned int value)
{
	value == 0 ? (proc->carry = 1) :
		(proc->carry = 0);
	proc->reg[(param->map[proc->pc + 6]) % MEM_SIZE - 1] = value;
}

void		handle_ld(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	arg;
	short int		r;

	arg = 0;
	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	r = (short)params->map[(proc->pc + 6) % MEM_SIZE] - 1;
	if (val->val1 == 2 && r > 0 && r < REG_NUMBER)
		arg = (unsigned int)handle_dir(params, proc, 4, 2);
	else if (val->val1 == 3 && r > 0 && r < REG_NUMBER)
		arg = (unsigned int)handle_ind(params, proc, 2, 2);
	if ((val->val1 == 2 || val->val1 == 3) && r > 0 && r < REG_NUMBER)
		load_value(params, proc, arg);
	proc->pc = (proc->pc + count_steps(val, 2)) % MEM_SIZE;
	free(val);
}
