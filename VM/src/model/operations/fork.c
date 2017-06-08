/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:45:48 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 21:19:37 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void	copy_process_on_the_top(t_param *param, t_processor *proc,
		unsigned int pc)
{
	t_processor	*new;
	int			i;

	i = 0;
	new = (t_processor *)malloc(sizeof(t_processor));
	new->carry = proc->carry;
	new->is_alive = 0;
	new->player = proc->player;
	new->waite_cycles = 0;
	new->pc = pc;
	while (i < 16)
	{
		new->reg[i] = proc->reg[i];
		i++;
	}
	new->next = param->processors;
	param->processors = new;
}

void		handle_fork(t_param *param, t_processor *proc)
{
	unsigned int	adr;

	param->amount_proc++;
	adr = (unsigned)(proc->pc +
			(handle_dir(param, proc, 2, 1) % IDX_MOD)) % MEM_SIZE;
	copy_process_on_the_top(param, proc, adr);
	proc->pc = (proc->pc + 3) % MEM_SIZE;
}
