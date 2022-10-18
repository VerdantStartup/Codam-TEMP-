/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:16:15 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/18 21:25:54 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	temp = -1;
// 	if (c == '\0')
// 		return ((char *)s + ft_strlen(s));
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			temp = i;
// 		i++;
// 	}
// 	if (temp != -1)
// 		return ((char *)s + temp);
// 	return (NULL);
// }

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	t;

	i = 0;
	t = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			t = i;
		i++;
	}
	if (c == 0)
		return ((char *)s + i);
	if (t < 0)
		return (0);
	return ((char *)s + t);
}
