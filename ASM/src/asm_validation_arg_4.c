/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_arg_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:18:21 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/03 15:33:48 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	check_st(t_valid_asm *file_s, t_param *param, int opcode)
{
	check_t_reg(file_s, param, opcode, 0);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'st')");
	file_s->arg++;
	chek_ind_reg(file_s, param, opcode);
}

void	check_add_sub(t_valid_asm *file_s, t_param *param, int opcode)
{
	check_t_reg(file_s, param, opcode, 0);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
	{
		if (opcode == 4)
			error_exit("Syntax error (format op-n 'add')");
		else
			error_exit("Syntax error (format op-n 'sub')");
	}
	file_s->arg++;
	check_t_reg(file_s, param, opcode, 0);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
	{
		if (opcode == 4)
			error_exit("Syntax error (format op-n 'add')");
		else
			error_exit("Syntax error (format op-n 'sub')");
	}
	file_s->arg++;
	check_t_reg(file_s, param, opcode, 1);
}

void	check_ldi_lldi(t_valid_asm *file_s, t_param *param, int opcode)
{
	chek_reg_dir_ind(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'ldi' 'lldi')");
	file_s->arg++;
	chek_dir_reg(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'end' 'xor')");
	check_t_reg(file_s, param, opcode, 1);
}

void	check_sti(t_valid_asm *file_s, t_param *param, int opcode)
{
	check_t_reg(file_s, param, opcode, 0);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'sti')");
	file_s->arg++;
	chek_reg_dir_ind(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'sti')");
	file_s->arg++;
	chek_dir_reg(file_s, param, opcode);
}

int		search_operation(t_valid_asm *file_s, char *str, t_param *param)
{
	int	opcode;
	int	j;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] && !ft_isprint(str[i]))
		i++;
	j = i;
	while (!ft_istab_space(str[j]) && str[j] != DIRECT_CHAR && str[j])
	{
		j++;
		len++;
	}
	if (str[i] == '\0')
		return (0);
	ft_strdel(&file_s->str_line);
	file_s->str_line = ft_strsub(str, i, len);
	if (!(opcode = cmp_operation(file_s->str_line)))
		return (0);
	push_operation(&param->oper_lst, (char)opcode, ++param->fc_count);
	file_s->arg = j;
	return (opcode);
}
