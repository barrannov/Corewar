/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 22:33:04 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:36:05 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	handle_add(t_param *params, t_processor *proc)
{
	t_val			*val;
	unsigned int	r1;
	unsigned int	r2;
	unsigned int	r3;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	r1 = params->map[(proc->pc + 2) % MEM_SIZE] - 1;
	r2 = params->map[(proc->pc + 3) % MEM_SIZE] - 1;
	r3 = params->map[(proc->pc + 4) % MEM_SIZE] - 1;
	if (val->val1 == 1 && val->val2 == 1 && val->val3 == 1 && r1 < 16 &&
			r2 < 16 && r3 < 16)
	{
		proc->reg[r3] = proc->reg[r1] + proc->reg[r2];
		proc->reg[r3] == 0 ? (proc->carry = 1) :
			(proc->carry = 0);
		proc->pc = (proc->pc + count_steps(val, 4)) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + count_steps(val, 4)) % MEM_SIZE;
	free(val);
}
