/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:21:38 by mwilsch           #+#    #+#             */
/*   Updated: 2022/10/26 23:11:09 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinbuffers(char *s1, char const *s2, size_t *size)
{
	char			*target;
	size_t			i;
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);

	i = 0;
	if (len_s1 + len_s2 < *size - 1) // if this is true then there is enough space in static buff = s1
		return (ft_strlcat(s1, (char *)s2, *size));
	*size *= 2;
	target = (char *)malloc((*size) * sizeof(char));
	if (target == NULL)
		return (NULL);
	while (i < len_s1 && s1[i])
	{
		target[i] = s1[i];
		i++;
	}
	target[i] = '\0';
	ft_strlcat(target, (char *)s2, *size);
	free(s1);
	return (target);
}

char	*ft_next_line(char *buf, char *current_line)
{
	int	len;
	char *next_line;
	
	len = ft_strlen(buf) - ft_strlen(current_line);
	next_line = ft_substr(buf,1 + ft_strclen(buf, '\n'), len);
	free(buf);
	return (next_line);
}

char *ft_return_line(char *static_buf)
{
	char *this_line;

	if (!static_buf)
		return (NULL);
	if (ft_strchr(static_buf, '\n')) // if strchr finds the \n then it evalueates to true
		this_line = ft_substr(static_buf, 0, 1 + ft_strclen(static_buf, '\n'));
	else
		this_line = ft_substr(static_buf, 0,+ ft_strclen(static_buf, '\n'));
	return (this_line);
}

char *ft_read(int fd,char *static_buf)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE + 1];
	size_t	buf_len;
	
	buf_len = BUFFER_SIZE + 1;
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buf);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buf[bytes_read] = '\0';
		static_buf = ft_joinbuffers(static_buf, buf, &buf_len);
	}
	return (static_buf);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		*thisline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!static_buf)
	{
		static_buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!static_buf)
			return (NULL);
		static_buf[0] = '\0';
		static_buf = ft_read(fd, static_buf);
	}
	else if (!ft_strchr(static_buf, '\n'))
		static_buf = ft_read(fd, static_buf);
	thisline = ft_return_line(static_buf);
	static_buf = ft_next_line(static_buf, thisline);
	return (thisline);
}

// int main(void)
// {
// 	int fd;
// 	fd = open("./test.txt", O_RDONLY);
// 	printf("1:%s",get_next_line(fd));
// 	printf("2:%s",get_next_line(fd));
// 	printf("3:%s",get_next_line(fd));
// 	// printf("3:%s",get_next_line(fd));
// 	// get_next_line(fd);
// 	close(fd);
// 	return (0);
// }


// int main(int ac, char **av)
// {
// 	char *line;

// 	while(line)
// 	{
// 		int fd = open(av[1], O_RDONLY);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	return 0;
// }