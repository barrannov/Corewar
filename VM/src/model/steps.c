/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:56:44 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/08 20:19:57 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

static short int	get_dir_indir_short(char val)
{
	if (val == 2 || val == 3)
		return (2);
	else
		return (0);
}

static short int	get_dir_indir_long(char val)
{
	if (val == 2)
		return (4);
	else if (val == 3)
		return (2);
	else
		return (0);
}

static short int	get_cod_byte(short int opcode)
{
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		return (1);
	else
		return (2);
}

short int			count_steps(t_val *val, short int opcode)
{
	short int	first;
	short int	second;
	short int	third;

	if (val->val1 == 1)
		first = 1;
	else if (val->val1 > 0 && opcode > 8 && opcode < 16 && opcode != 13)
		first = get_dir_indir_short(val->val1);
	else
		first = get_dir_indir_long(val->val1);
	if (val->val2 == 1)
		second = 1;
	else if (val->val2 > 0 && opcode > 8 && opcode < 16 && opcode != 13)
		second = get_dir_indir_short(val->val2);
	else
		second = get_dir_indir_long(val->val2);
	if (val->val3 == 1)
		third = 1;
	else if (val->val3 > 0 && opcode > 8 && opcode < 16 && opcode != 13)
		third = get_dir_indir_short(val->val3);
	else if (val->val3 > 0 && (opcode == 2 || opcode == 3 || opcode == 13))
		third = 0;
	else
		third = get_dir_indir_long(val->val3);
	return (first + second + third + get_cod_byte(opcode));
}
