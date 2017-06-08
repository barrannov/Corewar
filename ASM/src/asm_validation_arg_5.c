/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_arg_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:16:25 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/02 17:54:33 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	free_mas(char **mas)
{
	int		i;

	i = 0;
	while (mas[i])
	{
		ft_strdel(&mas[i]);
		i++;
	}
	free(mas);
}

void	del_com_name(char *str, int i)
{
	while (str[i])
	{
		str[i] = ' ';
		i++;
	}
}

void	handle_lable(t_valid_asm *file_s, t_param *param, int opcode, int fin)
{
	int		num;

	file_s->arg++;
	ft_strdel(&file_s->str_line);
	num = file_s->arg;
	while (!ft_istab_space(file_s->stream[file_s->num_str][file_s->arg]) &&
			file_s->stream[file_s->num_str][file_s->arg] &&
			file_s->stream[file_s->num_str][file_s->arg] != SEPARATOR_CHAR)
		file_s->arg++;
	file_s->str_line = ft_strsub(file_s->stream[file_s->num_str],
			num, file_s->arg - num);
	push_argument(param->oper_lst, file_s->type,
			ft_strdup(file_s->str_line), 0);
	if ((opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15) && fin)
		check_end_of_str(file_s);
}

int		is_valid_name(char *exp_name)
{
	char	*extension;

	extension = exp_name + ft_strlen(exp_name) - 2;
	if (!ft_strcmp(extension, ".s"))
		return (1);
	else
		return (0);
	return (1);
}

char	*get_file_name(char *name)
{
	char	*result;
	char	*del;

	result = ft_strnew(ft_strlen(name) - 2);
	ft_memmove(result, name, ft_strlen(name) - 2);
	del = result;
	result = ft_strjoin(result, ".cor");
	free(del);
	return (result);
}
