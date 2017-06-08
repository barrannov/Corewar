/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 17:34:21 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 21:20:04 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void		init_reg(t_processor *proc)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		proc->reg[i] = 0;
}

static void	add_process(t_param *params, short pc, int numb, int player_numb)
{
	t_processor	*new;

	new = malloc(sizeof(t_processor) + 1);
	new->pc = pc;
	init_reg(new);
	new->reg[0] = player_numb;
	new->carry = 0;
	new->waite_cycles = 0;
	new->is_alive = 0;
	new->player = numb;
	new->next = NULL;
	if (!params->processors)
		params->processors = new;
	else
	{
		new->next = params->processors;
		params->processors = new;
	}
}

void		get_processes(t_param *param)
{
	t_player	*tmp;
	int			numb;

	numb = 0;
	tmp = param->players;
	while (tmp)
	{
		add_process(param, (short)tmp->pos, ++numb, tmp->numb);
		tmp = tmp->next;
	}
}
