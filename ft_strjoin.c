/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:03:18 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/18 21:24:24 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*target;
	int		i;

	size = ft_strlen(s1) + ft_strlen(s2);
	target = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	if (target == NULL)
		return (NULL);
	ft_strlcpy(target, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcpy(target + ft_strlen(s1), (char *)s2, ft_strlen(s2) + 1);
	return (target);
}

// size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)

// int main(void)
// {
// 	char s1[] = "Elon ";
// 	char s2[] = "Musk";
// 	printf("%s", ft_strjoin(s1, s2));
// }

// Count the length of s1 and s2
// Malloc the result
// strlcpy s1 and s2 into the new string