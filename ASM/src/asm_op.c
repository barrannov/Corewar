/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:51:06 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/05/30 21:18:07 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		get_op(int number)
{
	if ((number >= 9 && number <= 12) || number == 14 || number == 15)
		return (1);
	else
		return (0);
}
