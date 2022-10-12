/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:42:34 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/11 21:44:49 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	int		*test;

	i = 0;
	test = (int *)malloc(count * size);
	if (test == NULL)
		return (NULL);
	while (i < count)
	{
		test[i] = '\0';
		i++;
	}
	return (test);
}

// int main()
// {
// 	size_t count = 0;
// 	size_t size = sizeof(int);
// 	// ft_calloc(count, size);
// 	int *test = ft_calloc(count, size);
// 	for (size_t i = 0; i < count; ++i)
// 		printf("%d ", test[i]);
// }
