/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_arg_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:44:10 by oborysen          #+#    #+#             */
/*   Updated: 2017/05/29 22:30:03 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	check_ld_lld(t_valid_asm *file_s, t_param *param, int opcode)
{
	chek_dir_ind(file_s, param, opcode);
	skip_char_unil_separator(file_s);
	if (file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		error_exit("Syntax error (format op-n 'ld' 'lld')");
	file_s->arg++;
	check_t_reg(file_s, param, opcode, 1);
}

void	chek_dir_reg(t_valid_asm *file_s, t_param *param, int opcode)
{
	while (ft_istab_space(file_s->stream[file_s->num_str][file_s->arg]))
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == DIRECT_CHAR)
	{
		if (opcode == 11)
			check_t_dir(file_s, param, opcode, 1);
		else
			check_t_dir(file_s, param, opcode, 0);
	}
	else if (file_s->stream[file_s->num_str][file_s->arg] == 'r')
	{
		if (opcode == 11)
			check_t_reg(file_s, param, opcode, 1);
		else
			check_t_reg(file_s, param, opcode, 0);
	}
	else
	{
		error_exit("Syntax error (format op-n T_DIR | T_REG)");
	}
}

void	chek_ind_reg(t_valid_asm *file_s, t_param *param, int opcode)
{
	while (ft_istab_space(file_s->stream[file_s->num_str][file_s->arg]))
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '-'
		|| (file_s->stream[file_s->num_str][file_s->arg] >= '0'
		&& file_s->stream[file_s->num_str][file_s->arg] <= '9') ||
		file_s->stream[file_s->num_str][file_s->arg] == LABEL_CHAR)
		check_t_ind(file_s, param, opcode, 1);
	else if (file_s->stream[file_s->num_str][file_s->arg] == 'r')
		check_t_reg(file_s, param, opcode, 1);
	else
	{
		error_exit("Syntax error (format op-n T_IND | T_REG)");
	}
}

void	chek_dir_ind(t_valid_asm *file_s, t_param *param, int opcode)
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
	else
	{
		error_exit("Syntax error (format op-n T_DIR | T_IND,)");
	}
}

int		is_lable_exist(t_lable *lable_lst, char *expecting_lable)
{
	if (!lable_lst)
		return (0);
	while (lable_lst)
	{
		if (!ft_strcmp(lable_lst->lable, expecting_lable))
			return (1);
		lable_lst = lable_lst->next;
	}
	return (0);
}
