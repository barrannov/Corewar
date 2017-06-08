/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:05:51 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/02 19:07:21 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	chek_label(t_valid_asm *file_s, t_param *param)
{
	int		i;
	int		opcode;

	i = 0;
	file_s->mas = asm_split(file_s->stream[file_s->num_str]);
	if (file_s->mas[0][0] == LABEL_CHAR ||
		chek_label_symbol(file_s->stream[file_s->num_str], param))
		error_exit("Syntax error (unknown symbol in label)");
	if (!(opcode = search_end_operation(file_s,
		file_s->stream[file_s->num_str], &i, param)))
		error_exit("Syntax error (incorrect operation in label)");
	file_s->label_oper++;
	free_mas(file_s->mas);
	if (opcode == 17)
	{
		file_s->not++;
		return ;
	}
	file_s->not++;
	if (check_arg(file_s, param, opcode))
		return ;
}

int		chek_label_symbol(char *str, t_param *param)
{
	int		i;
	int		j;
	int		len;
	char	*label;

	i = 0;
	len = 0;
	while (!ft_strchr(LABEL_CHARS, str[i]))
		i++;
	j = i;
	while (str[j] != LABEL_CHAR && str[j])
	{
		if (!ft_strchr(LABEL_CHARS, str[j]))
			return (1);
		j++;
		len++;
	}
	label = ft_strsub(str, i, len);
	if (!is_lable_exist(param->lable_lst, label))
	{
		push_lable(&param->lable_lst, label, param->fc_count + 1);
	}
	return (0);
}

int		search_end_operation(t_valid_asm *file_s, char *str, int *i,
							t_param *param)
{
	int	opcode;
	int	j;
	int	len;

	len = 0;
	while (str[*i] && str[*i] != LABEL_CHAR)
		(*i)++;
	(*i)++;
	while ((str[(*i)] == '\t' || str[(*i)] == ' ') && str[(*i)])
		(*i)++;
	if (str[(*i)] == '\0')
		return (17);
	j = (*i);
	while (!ft_istab_space(str[j]) && str[j] != DIRECT_CHAR && str[j])
	{
		j++;
		len++;
	}
	ft_strdel(&file_s->str_line);
	file_s->str_line = ft_strsub(str, (*i), len);
	if (!(opcode = cmp_operation(file_s->str_line)))
		return (0);
	push_operation(&param->oper_lst, (char)opcode, ++param->fc_count);
	file_s->arg = j;
	return (opcode);
}

int		cmp_operation(char *str)
{
	if (!ft_strcmp(str, "live"))
		return (1);
	if (!ft_strcmp(str, "ld"))
		return (2);
	if (!ft_strcmp(str, "st"))
		return (3);
	if (!ft_strcmp(str, "add"))
		return (4);
	if (!ft_strcmp(str, "sub"))
		return (5);
	if (!ft_strcmp(str, "and"))
		return (6);
	if (!ft_strcmp(str, "or"))
		return (7);
	if (!ft_strcmp(str, "xor"))
		return (8);
	if (!ft_strcmp(str, "zjmp"))
		return (9);
	if (!ft_strcmp(str, "ldi"))
		return (10);
	if (!ft_strcmp(str, "sti"))
		return (11);
	return (cmp_operation_2(str));
}

int		cmp_operation_2(char *str)
{
	if (!ft_strcmp(str, "fork"))
		return (12);
	if (!ft_strcmp(str, "lld"))
		return (13);
	if (!ft_strcmp(str, "lldi"))
		return (14);
	if (!ft_strcmp(str, "lfork"))
		return (15);
	if (!ft_strcmp(str, "aff"))
		return (16);
	return (0);
}
