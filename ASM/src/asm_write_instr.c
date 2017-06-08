/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_instr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:22:15 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/05/30 21:41:39 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

static void	set_short_value(char **str_code, short int value)
{
	char	*byte_ptr;

	byte_ptr = (char *)&value;
	(**str_code) = byte_ptr[1];
	(*str_code)++;
	(**str_code) = byte_ptr[0];
	(*str_code)++;
}

static void	set_int_value(char **str_code, int value)
{
	int		big_endian_val;
	char	*byte;
	int		index;

	big_endian_val = move_bits(value);
	byte = (char *)&big_endian_val;
	index = 0;
	while (index < DIR_SIZE)
	{
		(**str_code) = byte[index++];
		(*str_code)++;
	}
}

static void	write_code(t_arg *arg_iter, char **str_code, int op)
{
	if (arg_iter->arg_type == REG_CODE)
	{
		(**str_code) = arg_iter->arg_value;
		(*str_code)++;
	}
	else if (arg_iter->arg_type == IND_CODE ||
			(arg_iter->arg_type == DIR_CODE && op))
	{
		set_short_value(str_code, (short int)arg_iter->arg_value);
	}
	else
	{
		set_int_value(str_code, arg_iter->arg_value);
	}
}

static void	oper_code_to_str(t_oper *oper, char **str_code)
{
	t_arg	*arg_iter;
	int		op;

	op = get_op(oper->op_code);
	(**str_code) = oper->op_code;
	(*str_code)++;
	if (oper->arg_code_byte)
	{
		(**str_code) = oper->arg_code_byte;
		(*str_code)++;
	}
	arg_iter = oper->arg_lst;
	while (arg_iter)
	{
		write_code(arg_iter, str_code, op);
		arg_iter = arg_iter->next;
	}
}

void		write_instructions(t_param *par, int fd)
{
	t_oper	*oper_iter;
	char	*curr_pos;

	par->instr = (char *)malloc(par->prog_size);
	oper_iter = par->oper_lst;
	curr_pos = par->instr;
	while (oper_iter)
	{
		oper_code_to_str(oper_iter, &curr_pos);
		oper_iter = oper_iter->next;
	}
	write(fd, par->instr, par->prog_size);
}
