/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:25:41 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/12 22:18:14 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create index to loop through str
// Loop through str[i]
// if str[i] == c then return str[i]
// else return str

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	// if (!s)
	// 	return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// 	// char *d1 = strchr(src, '\0');
// 	char *d2 = ft_strchr(src, '\0');
// 	// printf("d1: %s", d1);
// 	printf("d2: %s", d2);
// }