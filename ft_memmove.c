/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:23:13 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 14:09:49 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		return (dest);
	}
	while (i++ < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

// int main()
// {
// 		// char d[] = "E"
// 		char s[] = "Elon Musk";
// 		size_t n = 6;
// 		ft_memmove(s + 2, s, n );
// 		// memmove(s + 2, s, n );
// 		printf("%s", s);
// }
