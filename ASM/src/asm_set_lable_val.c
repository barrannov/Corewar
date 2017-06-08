/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_set_lable_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:20:16 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/01 22:09:53 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

static int	find_op_number(t_lable *lable_lst, char *lable_name)
{
	while (lable_lst)
	{
		if (!ft_strcmp(lable_lst->lable, lable_name))
			return (lable_lst->fc_number);
		lable_lst = lable_lst->next;
	}
	return (0);
}

static int	get_lable_addr(t_param *par, char *lable_name)
{
	int		op_number;
	t_oper	*iter;

	op_number = find_op_number(par->lable_lst, lable_name);
	iter = par->oper_lst;
	while (iter)
	{
		if (iter->number == op_number)
			return (iter->addr);
		iter = iter->next;
	}
	return (par->prog_size);
}

void		set_label_value(t_param *par)
{
	t_oper	*op_iter;
	t_arg	*arg_iter;
	int		dest;
	int		src;

	op_iter = par->oper_lst;
	while (op_iter)
	{
		arg_iter = op_iter->arg_lst;
		while (arg_iter)
		{
			if (arg_iter->lable_name)
			{
				dest = get_lable_addr(par, arg_iter->lable_name);
				src = op_iter->addr;
				arg_iter->arg_value = (short)(dest - src);
			}
			arg_iter = arg_iter->next;
		}
		op_iter = op_iter->next;
	}
}
