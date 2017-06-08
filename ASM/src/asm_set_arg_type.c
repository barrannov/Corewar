/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_set_arg_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:17:32 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/05/30 21:43:54 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

static char		get_arg_type_byte(t_oper *oper)
{
	char	arg_byte;
	int		i;
	t_arg	*iter;

	if (oper->op_code == 1 || oper->op_code == 9 ||
			oper->op_code == 12 || oper->op_code == 15)
		return (0);
	else
	{
		arg_byte = 0;
		i = 0;
		iter = oper->arg_lst;
		while (i++ < 3)
		{
			if (iter)
				arg_byte |= iter->arg_type;
			arg_byte = arg_byte << 2;
			if (iter)
				iter = iter->next;
		}
	}
	return (arg_byte);
}

void			set_arg_type_bytes(t_param *par)
{
	t_oper	*oper;

	oper = par->oper_lst;
	while (oper)
	{
		oper->arg_code_byte = get_arg_type_byte(oper);
		oper = oper->next;
	}
}

static int		get_oper_len(t_oper *oper)
{
	int		len;
	t_arg	*iter;
	int		op;

	len = 2;
	if (oper->op_code == 1 || oper->op_code == 9 ||
			oper->op_code == 12 || oper->op_code == 15)
		len--;
	iter = oper->arg_lst;
	while (iter)
	{
		op = get_op(oper->op_code);
		if (iter->arg_type == REG_CODE)
			len += 1;
		else if (iter->arg_type == IND_CODE)
			len += 2;
		else if (iter->arg_type == DIR_CODE && op)
			len += 2;
		else if (iter->arg_type == DIR_CODE && !op)
			len += 4;
		iter = iter->next;
	}
	return (len);
}

unsigned int	set_oper_start_addr(t_param *par)
{
	t_oper	*iter;
	int		oper_addr;

	oper_addr = 0;
	iter = par->oper_lst;
	while (iter)
	{
		iter->addr = oper_addr;
		oper_addr += get_oper_len(iter);
		iter = iter->next;
	}
	return (oper_addr);
}

void			gv_function(t_param *par, t_param **par_lst, char *file_name)
{
	par->next = (*par_lst);
	(*par_lst) = par;
	ft_putstr("\e[92mWriting output program to ");
	ft_putendl(file_name);
	ft_putstr("\e[39m");
	free(file_name);
}
