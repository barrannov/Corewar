/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:22:51 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/11/29 20:20:46 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_cnt(char const *s)
{
	int		st;

	st = 0;
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st])
		st++;
	return (st);
}

static int	finish_cnt(char const *s)
{
	int		fn;

	fn = 0;
	while (*s)
	{
		fn++;
		s++;
	}
	s--;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && --fn > 0)
		s--;
	return (fn);
}

char		*ft_strtrim(char const *s)
{
	char	*trimed;
	int		fn;
	int		st;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	st = start_cnt(s);
	fn = finish_cnt(s);
	if (fn-- == 0)
	{
		if (!(trimed = (char *)malloc(1)))
			return (NULL);
		*trimed = '\0';
		return (trimed);
	}
	if (!(trimed = (char *)malloc((fn - st + 1) + 1)))
		return (NULL);
	while (st <= fn)
		trimed[i++] = s[st++];
	trimed[i] = '\0';
	return (trimed);
}
