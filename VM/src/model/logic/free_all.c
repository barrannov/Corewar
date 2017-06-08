/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oklymeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 23:47:16 by oklymeno          #+#    #+#             */
/*   Updated: 2017/06/09 00:01:22 by oklymeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vm_header.h"

static void	free_player(t_player *player)
{
	if (player->next)
		free_player(player->next);
	free(player->header);
	free(player->commands);
	free(player);
}

static void	free_processors(t_processor *proc)
{
	if (proc->next)
		free_processors(proc->next);
	free(proc);
}

void		vm_free_all(t_param *param)
{
	free_processors(param->processors);
	free(param->map);
	free(param->map_c);
	free_player(param->players);
	free(param);
}
