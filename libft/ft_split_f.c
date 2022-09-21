/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:38:05 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 16:07:39 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_count_words(char const *s, int (*funct)(int), size_t *j)
{
	size_t	in_a_word;
	size_t	word_count;

	if (s == NULL)
		return (0);
	*j = 0;
	in_a_word = 0;
	word_count = 0;
	while (*s)
	{
		if (in_a_word == 0 && (*funct)(*s) == 0)
			in_a_word = 1;
		if (in_a_word == 1 && ((*funct)(*s) || *(s + 1) == 0))
		{
			in_a_word = 0;
			word_count++;
		}
		s++;
	}
	return (word_count);
}

static size_t	ft_custom_strlen(const char *s, int (*funct)(int))
{
	size_t	i;

	i = 0;
	while (s[i] && (*funct)(s[i]) == 0)
		i++;
	return (i);
}

static size_t	ft_check_malloc(char **tab, char *str, size_t index)
{
	if (!str && index != 0)
	{
		while (index != 0)
		{
			free(tab[index - 1]);
			index--;
		}
		free(tab);
		return (0);
	}
	if (!str)
	{
		free(tab);
		return (0);
	}
	return (1);
}

char	**ft_split_f(char const *s, int (*funct)(int))
{
	char	**tab;
	size_t	word_count;
	size_t	i;
	size_t	j;
	size_t	word_length;

	i = -1;
	if (s == NULL)
		return (0);
	word_count = ft_count_words(s, funct, &j);
	tab = malloc(sizeof(*tab) * (word_count + 1));
	if (!tab)
		return (0);
	tab[word_count] = 0;
	while (++i < word_count)
	{
		while ((*funct)(s[j]))
			j++;
		word_length = ft_custom_strlen(&s[j], funct);
		tab[i] = ft_substr(s, j, (word_length));
		j += word_length;
		if (ft_check_malloc(tab, tab[i], i) == 0)
			return (0);
	}
	return (tab);
}
