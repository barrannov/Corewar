/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:48:41 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/01 22:22:37 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm_header.h"

int		check_arg(t_valid_asm *file_s, t_param *param, int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		check_t_dir(file_s, param, opcode, 1);
	if (opcode == 2 || opcode == 13)
		check_ld_lld(file_s, param, opcode);
	if (opcode == 3)
		check_st(file_s, param, opcode);
	if (opcode == 4 || opcode == 5)
		check_add_sub(file_s, param, opcode);
	if (opcode == 6 || opcode == 7 || opcode == 8)
		check_and_xor_or(file_s, param, opcode);
	if (opcode == 10 || opcode == 14)
		check_ldi_lldi(file_s, param, opcode);
	if (opcode == 11)
		check_sti(file_s, param, opcode);
	if (opcode == 16)
		check_t_reg(file_s, param, opcode, 1);
	file_s->not++;
	return (0);
}

int		handle_dir_char(char *src)
{
	if (*src == '-' || ft_isdigit(*src))
		src++;
	else
		return (0);
	while (*src && (*src != SEPARATOR_CHAR && *src != '\t' && *src != ' '))
	{
		if (!ft_isdigit(*src))
			return (0);
		src++;
	}
	return (1);
}

void	check_t_dir(t_valid_asm *file_s, t_param *param, int opcode, int fin)
{
	int	num;

	while (file_s->stream[file_s->num_str][file_s->arg] != DIRECT_CHAR
			&& file_s->stream[file_s->num_str][file_s->arg])
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '\0')
		error_exit("Syntax error (format T_DIR)");
	if (file_s->stream[file_s->num_str][file_s->arg] == DIRECT_CHAR)
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == LABEL_CHAR)
	{
		file_s->type = DIR_CODE;
		handle_lable(file_s, param, opcode, fin);
		return ;
	}
	if (file_s->stream[file_s->num_str][file_s->arg] == ' '
		|| file_s->stream[file_s->num_str][file_s->arg] == '\t')
		error_exit("Syntax error (format T_DIR, not integer)");
	if (!handle_dir_char(&file_s->stream[file_s->num_str][file_s->arg]))
		error_exit("Syntax error (format T_DIR, not integer)");
	num = ft_atoi(&file_s->stream[file_s->num_str][file_s->arg]);
	push_argument(param->oper_lst, DIR_CODE, NULL, num);
	if ((opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15) && fin)
		check_end_of_str(file_s);
}

void	check_t_reg(t_valid_asm *file_s, t_param *param, int opcode, int fin)
{
	int	num;

	while (file_s->stream[file_s->num_str][file_s->arg] != 'r'
			&& file_s->stream[file_s->num_str][file_s->arg])
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '\0')
		error_exit("Syntax error (format T_REG)");
	if (file_s->stream[file_s->num_str][file_s->arg] == 'r')
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] < '0'
		|| file_s->stream[file_s->num_str][file_s->arg] > '9')
		error_exit("Syntax error (format T_REG, not integer)");
	num = ft_atoi(&file_s->stream[file_s->num_str][file_s->arg]);
	if (num > REG_NUMBER || num < 0)
		error_exit("Syntax error (format T_REG, out of REG_NUMBER)");
	push_argument(param->oper_lst, REG_CODE, NULL, num);
	if (((opcode >= 2 && opcode <= 8) || opcode == 16 || opcode == 10
				|| opcode == 11 || opcode == 13 || opcode == 14) && fin)
		check_end_of_str(file_s);
}

void	check_end_of_str(t_valid_asm *file_s)
{
	while (!ft_istab_space(file_s->stream[file_s->num_str][file_s->arg])
			&& file_s->stream[file_s->num_str][file_s->arg])
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] == '\0')
		return ;
	while (ft_istab_space(file_s->stream[file_s->num_str][file_s->arg])
			&& file_s->stream[file_s->num_str][file_s->arg])
		file_s->arg++;
	if (file_s->stream[file_s->num_str][file_s->arg] != '\0')
		error_exit("Syntax error (other symbol)");
}
