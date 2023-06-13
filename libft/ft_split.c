/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:28 by Ben               #+#    #+#             */
/*   Updated: 2023/04/05 15:39:22 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_size(const char *str, char delemiter);
static int	count_words(const char *str, char delemiter);
static int	go_first_word(const char *str, char delemiter);
static void	*free_arr(char **str);

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	word_count;
	size_t	i;
	size_t	j;

	if (!s)
		word_count = 0;
	else
		word_count = count_words(s, c);
	str_arr = ft_calloc(word_count + 1, 8);
	if (!str_arr)
		return (NULL);
	i = 0;
	j = go_first_word(s, c);
	while (i < word_count)
	{
		str_arr[i] = ft_calloc(1, word_size(&s[j], c) + 1);
		if (!str_arr[i])
			return (free_arr(str_arr));
		ft_strlcpy(str_arr[i++], &s[j], word_size(&s[j], c) + 1);
		j += ft_go_next_word(&s[j], c);
	}
	str_arr[i] = 0;
	return (str_arr);
}

static int	count_words(const char *str, char delemiter)
{
	size_t	i;
	size_t	word_count;
	int		next_word_ready;

	i = 0;
	word_count = 0;
	next_word_ready = 1;
	while (str[i])
	{
		if (str[i] == delemiter)
			next_word_ready = 1;
		else if (next_word_ready == 1)
		{
			word_count++;
			next_word_ready = 0;
		}
		i++;
	}
	return (word_count);
}

static int	word_size(const char *str, char delemiter)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != delemiter)
		i++;
	return (i);
}

static int	go_first_word(const char *str, char delemiter)
{
	size_t	i;

	i = 0;
	if (str[i] && str[i] != delemiter)
		return (i);
	while (str[i] && str[i] == delemiter)
		i++;
	return (i);
}

static void	*free_arr(char **str_arr)
{
	size_t	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}
