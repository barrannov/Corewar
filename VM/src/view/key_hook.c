/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:35:21 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/03 15:24:58 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm_header.h"

void	key_hook(int flag)
{
	int	key;

	flag == 1 ? nodelay(stdscr, TRUE) : nodelay(stdscr, FALSE);
	key = getch();
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (key == 32)
	{
		flag == 1 ? key_hook(0) : key_hook(1);
		return ;
	}
	else if (key == 's')
	{
		nodelay(stdscr, FALSE);
		return ;
	}
}
