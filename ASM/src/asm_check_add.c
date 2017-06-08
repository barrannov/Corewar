/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:20:54 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/03 15:34:34 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

int		check_other_symbol(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '!' && str[i] <= '~')
			return (1);
		i++;
	}
	return (0);
}

int		is_print_symbol(int c)
{
	if (c >= '!' && c <= '~')
		return (1);
	return (0);
}

void	operation_check(t_valid_asm *file_s, t_param *param)
{
	int	opcode;

	if (!(opcode = search_operation(file_s,
				file_s->stream[file_s->num_str], param)))
		error_exit("Syntax error (incorrect operation)");
	check_arg(file_s, param, opcode);
	file_s->not++;
	return ;
}

int		str_operation(char *str)
{
	if (ft_strstr(str, "live"))
		return (1);
	if (ft_strstr(str, "ld"))
		return (2);
	if (ft_strstr(str, "st"))
		return (3);
	if (ft_strstr(str, "add"))
		return (4);
	if (ft_strstr(str, "sub"))
		return (5);
	if (ft_strstr(str, "and"))
		return (6);
	if (ft_strstr(str, "or"))
		return (7);
	if (ft_strstr(str, "xor"))
		return (8);
	if (ft_strstr(str, "zjmp"))
		return (9);
	if (ft_strstr(str, "ldi"))
		return (10);
	if (ft_strstr(str, "sti"))
		return (11);
	return (str_operation_2(str));
}

int		str_operation_2(char *str)
{
	if (ft_strstr(str, "fork"))
		return (12);
	if (ft_strstr(str, "lld"))
		return (13);
	if (ft_strstr(str, "lldi"))
		return (14);
	if (ft_strstr(str, "lfork"))
		return (15);
	if (ft_strstr(str, "aff"))
		return (16);
	return (0);
}
