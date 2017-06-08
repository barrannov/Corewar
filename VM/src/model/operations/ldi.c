/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 13:22:58 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:36:57 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static int			check_args_ldi(t_val *val)
{
	if (val->val1 != 1 && val->val1 != 2 && val->val1 != 3)
		return (0);
	if (val->val2 != 1 && val->val2 != 2)
		return (0);
	if (val->val3 != 1)
		return (0);
	return (1);
}

static short int	arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val1 == 1)
		return (proc->reg[params->map[(proc->pc + 2) % MEM_SIZE] - 1]);
	else if (val->val1 == 2)
		return (handle_dir(params, proc, 2, 2));
	else
		return (handle_ind(params, proc, 2, 10));
}

static short int	arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val1 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val2 == 1)
		return (proc->reg[params->map[(proc->pc + 2 + pos) % MEM_SIZE] - 1]);
	else
		return (handle_dir(params, proc, 2, 2 + pos));
}

void				handle_ldi(t_param *params, t_processor *proc)
{
	t_val		*val;
	short int	arg1;
	short int	arg2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	if (check_args_ldi(val))
	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		proc->reg[params->map[(proc->pc + count_steps(val, 10) - 1) % MEM_SIZE]
			- 1] = handle_dir(params, proc, REG_SIZE, (((arg1 + arg2)
							% IDX_MOD) % MEM_SIZE));
		proc->pc = (proc->pc + count_steps(val, 10)) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + count_steps(val, 10)) % MEM_SIZE;
	free(val);
}
