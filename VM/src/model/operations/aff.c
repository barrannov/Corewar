/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:16:27 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/07 20:33:10 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

void	handle_aff(t_param *params, t_processor *proc)
{
	char		res;
	short int	reg;

	reg = params->map[(proc->pc + 1) % MEM_SIZE] - 1;
	if (reg > 0 && reg < 16)
	{
		res = proc->reg[reg] % 256;
		ft_putchar(res);
		proc->pc = (proc->pc + 2) % MEM_SIZE;
	}
	else
		proc->pc = (proc->pc + 1) % MEM_SIZE;
}
