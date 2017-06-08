/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaranov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:09:13 by abaranov          #+#    #+#             */
/*   Updated: 2017/06/08 20:06:33 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void				sort_players(t_param *param)
{
	t_player	*tmpptr;
	t_player	*tmpnxt;
	int			tmp;

	tmpptr = param->players;
	tmpnxt = param->players->next;
	while (tmpnxt != NULL)
	{
		while (tmpnxt != tmpptr)
		{
			if (tmpnxt->numb > tmpptr->numb)
			{
				tmp = tmpptr->numb;
				tmpptr->numb = tmpnxt->numb;
				tmpnxt->numb = tmp;
			}
			tmpptr = tmpptr->next;
		}
		tmpptr = param->players;
		tmpnxt = tmpnxt->next;
	}
}

void				get_args(t_val *val, unsigned char *map, t_processor *proc)
{
	val->val1 = (map[proc->pc + 1] & 0xc0) >> 6;
	val->val2 = (map[proc->pc + 1] & 0x30) >> 4;
	val->val3 = (map[proc->pc + 1] & 0x0c) >> 2;
}
