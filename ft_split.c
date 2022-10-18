/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:54:34 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/18 21:12:27 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	counter;
	int		reset;

	counter = 0;
	reset = 1;
	while (*str)
	{
		if (*str != c && reset)
		{
			counter++;
			reset = 0;
		}
		else if (*str == c)
			reset = 1;
		str++;
	}
	return (counter);
}

static void	free_mem(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
}

static char	*store_wrd(const char *s, char c, char **arr, size_t i)
{
	size_t	len_word;
	char	*s_temp;

	len_word = 0;
	while (*s && *s != c)
	{
		len_word++;
		s++;
	}
	s_temp = ft_substr(s - len_word, 0, len_word);
	if (!s_temp)
	{
		free_mem(arr, i);
		*arr = NULL;
	}
	return (s_temp);
}

char	**ft_split(char const *s, char c)
{
	char	**split_pointers;
	size_t	i;
	size_t	word_count;
	char	*s_temp;

	i = 0;
	word_count = count_words((char *)s, c);
	s_temp = (char *)s;
	split_pointers = ft_calloc((word_count + 1), sizeof(char *));
	if (!s || !split_pointers)
		return (NULL);
	while (i < word_count)
	{
		if (*s != c)
		{
			s_temp = store_wrd(s, c, split_pointers, i);
			split_pointers[i++] = s_temp;
			s = s + ft_strlen(s_temp);
		}
		else
			s++;
	}
	return (split_pointers);
}
