/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:07:11 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/26 23:07:57 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_substr(char *src, unsigned int start, size_t len)
{
	int		size;
	char	*dest;
	int		i;

	size = len;
	// if (start >= ft_strlen(src))
	// {
	// 	dest = malloc(1);
	// 	dest[0] = '\0';
	// 	return (dest);
	// }
	if ((size_t)start + len >= ft_strlen(src))
		size = ft_strlen(src) - start;
	dest = (char *)malloc(size + 1 * sizeof(char));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < size)
		dest[i++] = src[start++];
	dest[i] = '\0';;;
	return (dest);
}

char	*ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (dst_len < dstsize - 1 && src[i])
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (dst);
}
