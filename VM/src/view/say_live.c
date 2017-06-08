/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_live.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:05:26 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/06 20:13:37 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/view.h"

void	say_live(char *name)
{
	ft_putstr("A process shows that player ");
	ft_putstr(name);
	ft_putstr(" is alive!\n");
}
