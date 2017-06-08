/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:31:34 by oborysen          #+#    #+#             */
/*   Updated: 2017/06/08 22:08:15 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_HEADER_H
# define ASM_HEADER_H

# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include "op.h"

# include <stdio.h>

# define INT_MAX	2147483647
# define GFD		0
# define FDN		1

typedef struct		s_arg
{
	char			arg_type;
	int				arg_value;
	char			*lable_name;
	struct s_oper	*lable;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_oper
{
	char			op_code;
	int				number;
	int				addr;
	char			arg_code_byte;
	struct s_arg	*arg_lst;
	struct s_oper	*next;
}					t_oper;

typedef struct		s_lable
{
	char			*lable;
	int				fc_number;
	struct s_lable	*next;
}					t_lable;

typedef struct		s_param
{
	char			*prog_name;
	char			*prog_comment;
	int				prog_size;
	struct s_oper	*oper_lst;
	struct s_lable	*lable_lst;
	char			*instr;
	int				fc_count;
	struct s_param	*next;
}					t_param;

typedef struct		s_validation_asm
{
	char			*str_line;
	char			*ff;
	char			**stream;
	char			**mas;
	int				num_str;
	int				num_i;
	int				num_com_name;
	int				not;
	int				oper;
	int				label_oper;
	int				arg;
	char			type;
}					t_valid_asm;

void				push_lable(t_lable **lable_lst, char *lable, int fc_number);
void				push_operation(t_oper **oper_lst, char opcode,\
									int fc_number);
void				push_argument(t_oper *oper_lst, char type,\
									char *lable_name, int value);
int					get_op(int number);
void				set_arg_type_bytes(t_param *par);
unsigned int		set_oper_start_addr(t_param *par);
void				write_instructions(t_param *par, int fd);
void				set_label_value(t_param *par);
unsigned int		move_bits(unsigned int num);
t_param				*validation(char *name);
int					is_valid_name(char *name);
char				*get_file_name(char *name);
void				gv_function(t_param *par, t_param **par_lst, char *name);
void				gv_function2(t_valid_asm *file_s);

/*
**validation function
*/

int					read_file_asm(t_valid_asm *file_s, int fd, char *line);
int					chek_format(t_valid_asm *file_s, t_param *param);
void				error_exit(char *str);
void				null_valid_asm(t_valid_asm *file_s);
char				**asm_split(char *str);
int					check_name(t_valid_asm *file_s, t_param *param);
int					count_str_in_mas(char **arr);
int					check_quotes(char *str);
int					check_comment(t_valid_asm *file_s, t_param *param);
int					skip_tab_space(char *str);
int					ft_istab_space(int c);
void				chek_label(t_valid_asm *file_s, t_param *param);
int					chek_label_symbol(char *str, t_param *param);
int					search_end_operation(t_valid_asm *file_s,\
									char *str, int *i, t_param *param);
int					cmp_operation(char *str);
int					cmp_operation_2(char *str);
int					check_arg(t_valid_asm *file_s, t_param *param, int opcode);
void				del_comments(t_valid_asm *file_s);
void				del_com(char *str, int *j);
int					check_other_symbol(char *str);
void				operation_check(t_valid_asm *file_s, t_param *param);
void				check_t_dir(t_valid_asm *file_s, t_param *param,\
								int opcode, int fin);
void				check_t_reg(t_valid_asm *file_s, t_param *param,\
								int opcode, int fin);
void				check_t_ind(t_valid_asm *file_s, t_param *param,\
								int opcode, int fin);
void				check_end_of_str(t_valid_asm *file_s);
int					str_operation(char *str);
int					str_operation_2(char *str);
int					check_label_in_str(char *str);
void				check_and_xor_or(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				skip_char_unil_separator(t_valid_asm *file_s);
void				chek_reg_dir_ind(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				chek_dir_reg(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				chek_ind_reg(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				chek_dir_ind(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				check_ld_lld(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				check_st(t_valid_asm *file_s, t_param *param, int opcode);
void				check_add_sub(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				check_ldi_lldi(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				check_sti(t_valid_asm *file_s, t_param *param,\
									int opcode);
void				check_add_sub(t_valid_asm *file_s, t_param *param,\
									int opcode);
int					is_lable_exist(t_lable *lable_lst,\
									char *expecting_lable);
int					search_operation(t_valid_asm *file_s, char *str,\
									t_param *param);
int					is_print_symbol(int c);
void				del_com_name(char *str, int i);
void				free_mas(char **mas);
void				handle_lable(t_valid_asm *file_s, t_param *param,\
									int opcode, int fin);
int					ft_isdigit_minus(int c);
void				check_new_line_at_end(int fd);

#endif
