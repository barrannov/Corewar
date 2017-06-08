/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:46:02 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/30 21:07:32 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prew;
	t_list	*new;
	t_list	*nbegin;

	if (!lst)
		return (NULL);
	new = f(lst);
	nbegin = new;
	prew = new;
	while (lst->next)
	{
		lst = lst->next;
		new = f(lst);
		prew->next = new;
		prew = new;
	}
	new->next = NULL;
	return (nbegin);
}
