/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:14:48 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/07 13:23:21 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_append(char *s1, const char *s2)
{
	char			*result;

	if (!s1)
	{
		result = (char *)malloc(sizeof(char) * ft_strlen(s2) + 1);
		if (!result)
			return (NULL);
		ft_memcpy(result, s2, ft_strlen(s2) + 1);
		return (result);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(result, s1, ft_strlen(s1));
	ft_memcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (result);
}

unsigned int	founded_next_line(char *res)
{
	unsigned int	i;

	if (!res)
		return (0);
	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

unsigned int	len_to_next_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

void	ft_strncpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*find_line(char *res)
{
	char			*line;
	unsigned int	size;

	if (!res)
		return (NULL);
	size = len_to_next_line(res);
	line = (char *)malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, res, size);
	return (line);
}
