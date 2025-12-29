/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:05:00 by raphalme          #+#    #+#             */
/*   Updated: 2025/12/29 19:32:25 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_fill_split(char **split, char const *s, char c);
static size_t	ft_count_words(char const *s, char c);
static void	ft_free_split(char **split, size_t i);


/*
** Alloue et retourne un tableau de chaines de caracteres obtenu en
** separant s a l'aide du caractere c.
** Le tableau est termine par NULL.
*/
char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (ft_fill_split(split, s, c));
}

static char	**ft_fill_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split[j] = ft_substr(s, start, i - start);
			if (!split[j++])
				return (ft_free_split(split, j - 1), NULL);
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
}
