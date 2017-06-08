/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 19:35:08 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:38:16 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void	write_value(t_param *params, t_processor *proc, unsigned int r)
{
	int	adr;
	int	ind;

	ind = (handle_dir(params, proc, 2, 3));
	adr = proc->pc + (ind % IDX_MOD);
	if (adr < 0)
		adr = adr + MEM_SIZE;
	params->map[adr] = proc->reg[r] >> 24;
	params->map[adr + 1] = (proc->reg[r] << 8) >> 24;
	params->map[adr + 2] = (proc->reg[r] << 16) >> 24;
	params->map[adr + 3] = (proc->reg[r] << 24) >> 24;
	params->map_c[adr] = 256 - proc->player;
	params->map_c[adr + 1] = 256 - proc->player;
	params->map_c[adr + 2] = 256 - proc->player;
	params->map_c[adr + 3] = 256 - proc->player;
}

void		handle_st(t_param *params, t_processor *proc)
{
	t_val		*val;
	short int	r1;
	short int	r2;

	val = malloc(sizeof(t_val));
	get_args(val, params->map, proc);
	r1 = params->map[((proc->pc + 2) % MEM_SIZE)];
	r2 = params->map[((proc->pc + 3) % MEM_SIZE)];
	if (val->val1 == 1 && val->val2 == 1 && r1 > 0 && r1 <= REG_NUMBER &&
			r2 > 0 && r2 <= REG_NUMBER)
	{
		proc->reg[params->map[r2 - 1]] = proc->reg[r1 - 1];
		proc->pc = (proc->pc + count_steps(val, 3)) % MEM_SIZE;
	}
	else if (val->val1 == 1 && val->val2 == 3 && r1 > 0 && r1 <= REG_NUMBER)
	{
		write_value(params, proc, r1 - 1);
		proc->pc = (proc->pc + count_steps(val, 3)) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + count_steps(val, 3)) % MEM_SIZE;
	free(val);
}
