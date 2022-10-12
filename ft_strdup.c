/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:17:53 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/12 21:04:01 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *source)
{
	int		i;
	int		size;
	char	*target;

	if (!source)
	return 0;
	size = ft_strlen(source);
	i = 0;
	target = (char *)malloc(size * sizeof(char) + 1);
	if (target == NULL)
		return (NULL);
	while (i < size)
	{
		target[i] = source[i];
		i++;
	}
	target[i] = 0;
	return (target);
}

// int main()
// {
// 	char source[] = "GeeksForGeeks";

// 	char *target = ft_strdup(source);
// 	printf("%s\t", target);

// 	char *target1 = strdup(source);
// 	printf("%s", target1);

// 	return 0;
// }
