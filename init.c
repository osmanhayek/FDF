/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:05:19 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/25 23:44:19 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_width(char **av)
{
	int		fd;
	int		width;
	int		temp_width;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	width = ft_count(line, ' ');
	while (line)
	{
		temp_width = ft_count(line, ' ');
		if (temp_width != width)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

int	ft_get_height(char **av)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	ft_fill_point(t_data *data, char **elements, int i)
{
	int		j;
	char	**to_fill;

	j = 0;
	while (elements[j])
	{
		to_fill = ft_split(elements[j], ',');
		data->points[i][j].z = ft_atoi(to_fill[0]);
		if (!to_fill[1])
			data->points[i][j].color = 0xffffff;
		else
			data->points[i][j].color = ft_atoi_base(&to_fill[1][2], 16);
		free_split(to_fill);
		j++;
	}
}

void	ft_fill_matrix(t_data *data, char *av)
{
	int		fd;
	int		i;
	char	*line;
	char	**elements;

	fd = open(av, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		data->points[i] = (t_point *)malloc(sizeof(t_point) * data->width);
		line = get_next_line(fd);
		elements = ft_split(line, ' ');
		ft_fill_point(data, elements, i);
		free_split(elements);
		free(line);
		i++;
	}
	close(fd);
}

void	ft_init_data(t_data **data, char **av)
{
	int	height;
	int	width;

	height = ft_get_height(av);
	width = ft_get_width(av);
	if (height <= 0 || width <= 0)
	{
		ft_putstr_fd("dosyalarin bok gibi duzelt onlari!\n", 2);
		exit(1);
	}
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return ;
	(*data)->height = height;
	(*data)->width = width;
	(*data)->points = (t_point **)malloc(sizeof(t_point *) * (height));
	if (!(*data)->points)
	{
		free(*data);
		*data = NULL;
		return ;
	}
	ft_fill_matrix(*data, av[1]);
}
