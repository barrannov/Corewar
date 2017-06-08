/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:17:15 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 17:13:14 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*data;

	data = (void *)content;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content)
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		new->content_size = content_size;
		ft_memmove(new->content, content, content_size);
	}
	else
		new->content = NULL;
	return (new);
}
