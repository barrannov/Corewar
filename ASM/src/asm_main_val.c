/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 18:26:40 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/09 19:14:17 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_header.h"

t_param		*validation(char *name)
{
	int			fd;
	t_valid_asm	*file_s;
	t_param		*param;
	char		*line;

	line = NULL;
	file_s = (t_valid_asm*)malloc(sizeof(t_valid_asm));
	param = (t_param*)malloc(sizeof(t_param));
	param->fc_count = -1;
	param->oper_lst = NULL;
	param->lable_lst = NULL;
	null_valid_asm(file_s);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		error_exit("Error: File doesn't exist");
	read_file_asm(file_s, fd, line);
	del_comments(file_s);
	chek_format(file_s, param);
	free_mas(file_s->stream);
	ft_strdel(&file_s->str_line);
	free(file_s);
	if (file_s->num_com_name != 2)
		error_exit("Error: name or comment tag incorrect");
	return (param);
}

void		del_comments(t_valid_asm *file_s)
{
	int		i;
	int		j;

	i = 0;
	while (file_s->stream[i])
	{
		j = 0;
		while (file_s->stream[i][j])
		{
			if (file_s->stream[i][j] == COMMENT_CHAR)
			{
				del_com(file_s->stream[i], &j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void		del_com(char *str, int *j)
{
	while (str[(*j)])
	{
		str[(*j)] = ' ';
		(*j)++;
	}
}

int			ft_isdigit_minus(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

int			skip_tab_space(char *str)
{
	int		i;

	i = 0;
	while (ft_istab_space(str[i]))
		i++;
	while (!ft_istab_space(str[i]))
		i++;
	while (ft_istab_space(str[i]))
		i++;
	return (i);
}
