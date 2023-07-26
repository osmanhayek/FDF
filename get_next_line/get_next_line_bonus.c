/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:15:12 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/11 23:01:03 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!n || src == dest)
		return (dest);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}

void	create_res(char **res, int fd)
{
	char			buf[BUFFER_SIZE + 1];
	unsigned int	read_tracker;

	while (!founded_next_line(*res))
	{
		read_tracker = read(fd, buf, BUFFER_SIZE);
		if (!read_tracker)
			return ;
		buf[read_tracker] = '\0';
		*res = ft_append(*res, buf);
	}
}

char	*clean_res(char *res)
{
	char			*new_buf;
	unsigned int	i;
	unsigned int	k;

	i = len_to_next_line(res);
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	new_buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_buf)
		return (NULL);
	k = 0;
	while (res[i])
		new_buf[k++] = res[i++];
	new_buf[k] = '\0';
	free(res);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*res[257] = {NULL};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 256)
	{
		if (fd >= 0 && fd <= 256)
		{
			if (res[fd])
				free(res[fd]);
			res[fd] = NULL;
		}
		return (NULL);
	}
	create_res(&res[fd], fd);
	if (!res[fd])
		return (NULL);
	line = find_line(res[fd]);
	res[fd] = clean_res(res[fd]);
	return (line);
}
