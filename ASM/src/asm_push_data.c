/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_push_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:49 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/05/28 15:07:58 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	push_lable(t_lable **lable_lst, char *lable, int fc_number)
{
	t_lable	*new;
	t_lable	*iter;

	new = (t_lable *)malloc(sizeof(t_lable));
	new->lable = lable;
	new->fc_number = fc_number;
	new->next = NULL;
	if (!*lable_lst)
	{
		*lable_lst = new;
	}
	else
	{
		iter = *lable_lst;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

void	push_operation(t_oper **oper_lst, char opcode, int fc_number)
{
	t_oper	*new;
	t_oper	*iter;

	new = (t_oper *)malloc(sizeof(t_oper));
	new->op_code = opcode;
	new->number = fc_number;
	new->arg_lst = NULL;
	new->next = NULL;
	if (!*oper_lst)
	{
		*oper_lst = new;
	}
	else
	{
		iter = *oper_lst;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}

void	push_argument(t_oper *oper_lst, char type, char *lable_name, int value)
{
	t_arg	*new;
	t_arg	*iter;

	while (oper_lst->next)
		oper_lst = oper_lst->next;
	new = (t_arg *)malloc(sizeof(t_arg));
	new->arg_type = type;
	new->arg_value = value;
	new->lable_name = lable_name;
	new->lable = NULL;
	new->next = NULL;
	if (!oper_lst->arg_lst)
	{
		oper_lst->arg_lst = new;
	}
	else
	{
		iter = oper_lst->arg_lst;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
}
