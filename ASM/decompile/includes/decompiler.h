/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 12:02:28 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/08 23:45:24 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECOMPILER_H
# define DECOMPILER_H

# include <fcntl.h>
# include "../../../libft/libft.h"
# include "op.h"

# define ERROR_STREAM	2

/*
**		algorithm.c
*/

void					write_algorythm(char *cor_name,
		t_header *header, char *code, int prog_len);

/*
**		value_manipulations.c
*/

unsigned int			move_bits(unsigned int num);
short					get_short_value(char *code, int iter);
int						get_int_value(char *code, int iter);
int						check_header(t_header *header, int fd);
char					*get_file_name(char *cor_name);

/*
**		write_oper_1_5.c
*/

void					write_live(int fd, char *code, int *i);
void					write_ld(int fd, char *code, int *i);
void					write_st(int fd, char *code, int *i);
void					write_add(int fd, char *code, int *i);
void					write_sub(int fd, char *code, int *i);

/*
**		write_oper_6_10.c
*/

void					write_and(int fd, char *code, int *i);
void					write_or(int fd, char *code, int *i);
void					write_xor(int fd, char *code, int *i);
void					write_zjmp(int fd, char *code, int *i);
void					write_ldi(int fd, char *code, int *i);

/*
**		write_oper_11_15.c
*/

void					write_sti(int fd, char *code, int *i);
void					write_fork(int fd, char *code, int *i);
void					write_lld(int fd, char *code, int *i);
void					write_lldi(int fd, char *code, int *i);
void					write_lfork(int fd, char *code, int *i);

/*
**		write_types.c
*/

void					write_dir(int fd, char *code, int *i, int flag);
void					write_reg(int fd, char *code, int *i);
void					write_ind(int fd, char *code, int *i);
void					write_aff(int fd, char *code, int *i);

#endif
