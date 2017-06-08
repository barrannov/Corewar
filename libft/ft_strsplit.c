/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:36:41 by dkhlopov          #+#    #+#             */
/*   Updated: 2016/12/02 17:47:12 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (str[i] != c && str[i + 1] == c && str[i + 1])
			j++;
		i++;
	}
	if (str[i - 1] == c)
		j--;
	return (j + 2);
}

static int	count_letr(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	s -= len;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(count_words(s, c) * sizeof(char *))))
		return (NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		j = 0;
		if (!(arr[i] = (char *)malloc(count_letr(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
			arr[i][j++] = *s++;
		arr[i++][j] = '\0';
		while (*s == c && *s)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
