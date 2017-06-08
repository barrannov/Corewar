/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:27:25 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:37:11 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static int	check_args_lldi(t_val *val)
{
	if (val->val1 != 1 && val->val1 != 2 && val->val1 != 3)
		return (0);
	if (val->val2 != 1 && val->val2 != 2)
		return (0);
	if (val->val3 != 1)
		return (0);
	return (1);
}

static int	arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val1 == 1)
		return (proc->reg[params->map[(proc->pc + 2) % MEM_SIZE] - 1]);
	else if (val->val1 == 2)
		return (handle_dir(params, proc, 2, 2));
	else
		return (handle_ind(params, proc, 2, 14));
}

static int	arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val1 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val2 == 1)
		return (proc->reg[params->map[(proc->pc + 2 + pos) % MEM_SIZE] - 1]);
	else
		return (handle_dir(params, proc, 2, 2 + pos));
}

void		handle_lldi(t_param *params, t_processor *proc)
{
	t_val		*val;
	int			arg1;
	int			arg2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	if (check_args_lldi(val))
	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		proc->reg[params->map[(proc->pc + count_steps(val, 14) - 1) % MEM_SIZE]
			- 1] = handle_dir(params, proc, REG_SIZE,
					((proc->pc + ((arg1 + arg2) % IDX_MOD) % MEM_SIZE)));
		proc->reg[params->map[(proc->pc + count_steps(val, 14)) - 1 % MEM_SIZE]
			- 1] == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
		proc->pc = (proc->pc + count_steps(val, 14)) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + count_steps(val, 14)) % MEM_SIZE;
	free(val);
}
