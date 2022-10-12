/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:35:10 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/12 22:32:34 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;
	size_t	temp;

	i = 0;
	i2 = 0;
	if (dst[i] == '\0')
	{
		while (src[i2])
			i2++;
		return (i2);
	}
	while (dst[i])
		i++;
	temp = i;
	while (src[i2] && i < dstsize - 1)
	{
		dst[i] = src[i2];
		i++;
		i2++;
	}
	while (src[i2])
		i2++;
	dst[i] = '\0';
	return (temp + i2);
}

int main()
{
	char *str = "n\0AA";
	char buff1[0xF00] = "\0AAAAAAAAAAAAAAAA";
	char buff2[0xF00] = "\0AAAAAAAAAAAAAAAA";
	size_t max = 10;
	printf("%lu ", strlcat(buff1, str, max));
	printf("%s ", buff1);
	printf("%lu ", ft_strlcat(buff2, str, max));
	printf("%s", buff2);
}
