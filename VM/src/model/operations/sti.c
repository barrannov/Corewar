/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:41:23 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 19:19:19 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static int			check_args_sti(t_val *val)
{
	if (val->val1 != 1)
		return (0);
	if (val->val2 != 1 && val->val2 != 2 && val->val2 != 3)
		return (0);
	if (val->val3 != 1 && val->val3 != 2)
		return (0);
	return (1);
}

static void			write_value(t_param *params, t_processor *proc,
		short int r, int adr)
{
	adr = adr % MEM_SIZE;
	if (adr < 0)
		adr = adr + MEM_SIZE;
	params->map[adr] = proc->reg[r] >> 24;
	params->map[adr + 1] = (proc->reg[r] << 8) >> 24;
	params->map[adr + 2] = (proc->reg[r] << 16) >> 24;
	params->map[adr + 3] = (proc->reg[r] << 24) >> 24;
	params->map_c[adr] = proc->player;
	params->map_c[adr + 1] = proc->player;
	params->map_c[adr + 2] = proc->player;
	params->map_c[adr + 3] = proc->player;
}

static int			arg_1(t_param *params, t_processor *proc, t_val *val)
{
	if (val->val2 == 1)
		return (proc->reg[params->map[(proc->pc + 3) % MEM_SIZE] - 1]);
	else if (val->val2 == 2)
		return (handle_dir(params, proc, 2, 3));
	else
		return (handle_ind(params, proc, 3, 11));
}

static int			arg_2(t_param *params, t_processor *proc, t_val *val)
{
	char	pos;

	val->val2 == 1 ? (pos = 1) :
		(pos = 2);
	if (val->val3 == 1)
		return (proc->reg[params->map[(proc->pc + 3 + pos) % MEM_SIZE] - 1]);
	else
		return (handle_dir(params, proc, 2, 3 + pos));
}

void				handle_sti(t_param *params, t_processor *proc)
{
	t_val		*val;
	int			arg1;
	int			arg2;
	short int	reg_n;

	val = (t_val*)malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	reg_n = params->map[(proc->pc + 2) % MEM_SIZE] - 1;
	if (check_args_sti(val))
	{
		arg1 = arg_1(params, proc, val);
		arg2 = arg_2(params, proc, val);
		write_value(params, proc, reg_n, proc->pc + arg1 + arg2);
		proc->pc = (proc->pc + count_steps(val, 11)) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + count_steps(val, 11)) % MEM_SIZE;
	free(val);
}
