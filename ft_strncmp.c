/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:37:12 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 13:57:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && ((unsigned char)s1[i] == (unsigned char)s2[i]))
	{
		if ((unsigned char)s1[i] == '\0' || (unsigned char)s2[i] == '\0')
			return (0);
		n--;
		i++;
	}
	if (n != 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

// int main ()
// {
// 	char s1[] = "ABCDEF";
// 	char s2[] = "ABCDEF";
// 	size_t n = 10;
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// 	printf("%d", strncmp(s1, s2, n));
// }
