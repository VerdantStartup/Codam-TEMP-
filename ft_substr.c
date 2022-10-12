/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:52:37 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/12 21:15:07 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters:   
	// s: The string from which to create the substring. 
	//start: The start index of the substring in the string ’s’.
	//len: The maximum length of the substring.
// Discription:  Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
// Return value: The substring. or NULL if the allocation fails
#include "libft.h"

char	*ft_substr(char const *src, unsigned int start,size_t len)
{
	int		size;
	char	*dest;
	int		i;

	size = len;
	if (start >= ft_strlen(src))
		return (ft_strdup(""));
	if ((size_t)start + len >= ft_strlen(src))
		size = ft_strlen(src) - start;
	dest = (char *)malloc(size + 1 * sizeof(char));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < size)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}


// int main()
// {
//     char *src = "01234";
//     size_t size = 10;
 
//     char* dest = ft_substr(src, 10, size);
 
//     printf("%s\n", dest);
 
//     return 0;
// }

//"hi" start 10 

// 1. Get the length of the characters which shall be substringed
// 2. malloc enough space into a new char pointer
// 3. copy src[i] to dest[i] from m to n - 1

