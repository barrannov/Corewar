/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:25:43 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/03 18:51:56 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

void	gv_function2(t_valid_asm *file_s)
{
	file_s->num_com_name++;
	file_s->not++;
	del_com_name(file_s->stream[file_s->num_str], 0);
	free_mas(file_s->mas);
}

int		read_file_asm(t_valid_asm *file_s, int fd, char *line)
{
	while (get_next_line(fd, &line))
	{
		file_s->ff = file_s->str_line;
		if (file_s->str_line == NULL)
			file_s->str_line = ft_strdup(line);
		else
			file_s->str_line = ft_strjoin(file_s->str_line, line);
		ft_strdel(&file_s->ff);
		file_s->ff = file_s->str_line;
		file_s->str_line = ft_strjoin(file_s->str_line, "\n");
		ft_strdel(&file_s->ff);
		ft_strdel(&line);
	}
	if (file_s->str_line != NULL)
	{
		file_s->stream = ft_strsplit(file_s->str_line, 10);
		ft_strdel(&line);
	}
	if (file_s->stream == NULL)
		error_exit("File is empty");
	check_new_line_at_end(fd);
	return (1);
}

int		chek_format(t_valid_asm *file_s, t_param *param)
{
	while (file_s->stream[file_s->num_str])
	{
		file_s->not = 0;
		file_s->label_oper = 0;
		if (ft_strstr(file_s->stream[file_s->num_str], NAME_CMD_STRING))
			if (!check_name(file_s, param))
				error_exit("Lexical error at name ");
		if (ft_strstr(file_s->stream[file_s->num_str], COMMENT_CMD_STRING))
			if (!check_comment(file_s, param))
				error_exit("Lexical error at comment ");
		if ((ft_strstr(file_s->stream[file_s->num_str], NAME_CMD_STRING) ||
					ft_strstr(file_s->stream[file_s->num_str],
						COMMENT_CMD_STRING)) && file_s->num_com_name > 2)
			error_exit("Lexical error no name or comment ");
		if (ft_strchr(file_s->stream[file_s->num_str], LABEL_CHAR) &&
				check_label_in_str(file_s->stream[file_s->num_str]))
			chek_label(file_s, param);
		if (file_s->num_com_name && !file_s->label_oper &&
				(file_s->oper = str_operation(file_s->stream[file_s->num_str])))
			operation_check(file_s, param);
		if (check_other_symbol(file_s->stream[file_s->num_str]) && !file_s->not)
			error_exit("Syntax error (unknown symbol)");
		file_s->num_str++;
	}
	return (1);
}

void	error_exit(char *str)
{
	ft_putstr("\e[91m");
	ft_putendl_fd(str, FDN);
	ft_putstr("\e[97m");
	exit(1);
}

void	null_valid_asm(t_valid_asm *file_s)
{
	file_s->stream = NULL;
	file_s->mas = NULL;
	file_s->str_line = NULL;
	file_s->ff = NULL;
	file_s->num_str = 0;
	file_s->num_i = 0;
	file_s->num_com_name = 0;
}
