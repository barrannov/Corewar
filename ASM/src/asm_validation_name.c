/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_validation_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:52:44 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/01 22:24:04 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

int		check_name(t_valid_asm *file_s, t_param *param)
{
	int	len;
	int	i;

	file_s->mas = asm_split(file_s->stream[file_s->num_str]);
	if (count_str_in_mas(file_s->mas) < 2 ||
		ft_strcmp(file_s->mas[0], NAME_CMD_STRING))
		return (0);
	i = skip_tab_space(file_s->stream[file_s->num_str]);
	file_s->ff = file_s->str_line;
	file_s->str_line = ft_strsub(file_s->stream[file_s->num_str], i,
									ft_strlen(file_s->stream[file_s->num_str]));
	ft_strdel(&file_s->ff);
	if (!check_quotes(file_s->str_line))
		return (0);
	len = (int)ft_strlen(file_s->str_line);
	if (len == 2)
	{
		param->prog_name = NULL;
		gv_function2(file_s);
		return (1);
	}
	else
		param->prog_name = ft_strsub(file_s->str_line, 1, len - 2);
	gv_function2(file_s);
	return (1);
}

int		check_comment(t_valid_asm *file_s, t_param *param)
{
	int len;
	int i;

	file_s->mas = asm_split(file_s->stream[file_s->num_str]);
	if (count_str_in_mas(file_s->mas) < 2 ||
		ft_strcmp(file_s->mas[0], COMMENT_CMD_STRING))
		return (0);
	i = skip_tab_space(file_s->stream[file_s->num_str]);
	file_s->ff = file_s->str_line;
	file_s->str_line = ft_strsub(file_s->stream[file_s->num_str], i,
								ft_strlen(file_s->stream[file_s->num_str]));
	ft_strdel(&file_s->ff);
	if (!check_quotes(file_s->str_line))
		return (0);
	len = (int)ft_strlen(file_s->str_line);
	if (len == 2)
	{
		param->prog_comment = NULL;
		gv_function2(file_s);
		return (1);
	}
	else
		param->prog_comment = ft_strsub(file_s->str_line, 1, len - 2);
	gv_function2(file_s);
	return (1);
}

int		count_str_in_mas(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		check_quotes(char *str)
{
	if (str[0] != '"' || ft_strlen(str) < 2)
		return (0);
	if (str[ft_strlen(str) - 1] != '"')
		return (0);
	return (1);
}

int		ft_istab_space(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}
