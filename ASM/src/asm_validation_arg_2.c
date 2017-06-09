/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_arg_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:41:58 by oborysen          #+#    #+#             */
/*   Updated: 2017/05/29 22:04:17 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	check_t_ind(t_valid_asm *file_s, t_param *param, int opcode, int fin)
{
	int		num;

	while (!ft_isdigit_minus(file_s->stream[file_s->num_str][file_s->arg])
			&& file_s->stream[file_s->num_str][file_s->arg] &&
			file_s->stream[file_s->num_str][file_s->arg] != LABEL_CHAR)
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '\0')
		error_exit("Syntax error (format T_IND)");
	if (file_s->stream[file_s->num_str][file_s->arg] == ' '
		|| file_s->stream[file_s->num_str][file_s->arg] == '\t')
		error_exit("Syntax error (format T_IND, not integer)");
	if (file_s->stream[file_s->num_str][file_s->arg] == LABEL_CHAR)
	{
		file_s->type = IND_CODE;
		handle_lable(file_s, param, opcode, fin);
		return ;
	}
	if (!handle_dir_char(&file_s->stream[file_s->num_str][file_s->arg]))
		error_exit("Syntax error (format T_IND, not integer)");
	num = ft_atoi(&file_s->stream[file_s->num_str][file_s->arg]);
	push_argument(param->oper_lst, IND_CODE, NULL, num);
	if ((opcode == 3 || opcode == 11) && fin)
		check_end_of_str(file_s);
}

int		check_label_in_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
		i++;
	if (str[i] == LABEL_CHAR && i != 0)
	{
		i--;
		if (ft_strchr(LABEL_CHARS, str[i]))
			return (1);
	}
	return (0);
}

void	check_and_xor_or(t_valid_asm *file_s, t_param *param, int opcode)
{
	chek_reg_dir_ind(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'end' 'xor')");
	file_s->arg++;
	chek_reg_dir_ind(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'end' 'xor')");
	check_t_reg(file_s, param, opcode, 1);
}

void	chek_reg_dir_ind(t_valid_asm *file_s, t_param *param, int opcode)
{
	while (ft_istab_space(file_s->stream[file_s->num_str][file_s->arg]))
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '-'
		|| (file_s->stream[file_s->num_str][file_s->arg] >= '0'
		&& file_s->stream[file_s->num_str][file_s->arg] <= '9') ||
		file_s->stream[file_s->num_str][file_s->arg] == LABEL_CHAR)
		check_t_ind(file_s, param, opcode, 0);
	else if (file_s->stream[file_s->num_str][file_s->arg] == DIRECT_CHAR)
		check_t_dir(file_s, param, opcode, 0);
	else if (file_s->stream[file_s->num_str][file_s->arg] == 'r')
		check_t_reg(file_s, param, opcode, 0);
	else
	{
		if (opcode == 6 || opcode == 7 || opcode == 8)
			error_exit("Syntax error (format op-n end xor or)");
		if (opcode == 10)
			error_exit("Syntax error (format ldi)");
		if (opcode == 11)
			error_exit("Syntax error (format sti)");
		if (opcode == 14)
			error_exit("Syntax error (format lldi)");
	}
}

void	skip_char_unil_separator(t_valid_asm *file_s)
{
	char	c;

	while (is_print_symbol(file_s->stream[file_s->num_str][file_s->arg])
			&& file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		file_s->arg++;
	while ((file_s->stream[file_s->num_str][file_s->arg] == ' ' ||
			file_s->stream[file_s->num_str][file_s->arg] == '\t')
			&& file_s->stream[file_s->num_str][file_s->arg])
		file_s->arg++;
	c = file_s->stream[file_s->num_str][file_s->arg];
}
