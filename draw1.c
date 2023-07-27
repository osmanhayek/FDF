/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:48:57 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 04:21:56 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_ratio(t_data *data, double *ratio, int y, int x)
{
	if (data->points[y][x].z < 10.0)
		*ratio = 1;
	else
		*ratio = 10.0 / 100.0;
}

void	ft_shift_zoom(t_data *data, t_zoom zoom)
{
	int		y;
	int		x;
	double	ratio;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->points[y][x].iso_x = (data->points[y][x].iso_x - zoom.min_x) \
			* zoom.scale_x;
			data->points[y][x].iso_y = (data->points[y][x].iso_y - zoom.min_y) \
			* zoom.scale_y;
			data->points[y][x].iso_x += (1000 - (zoom.max_x - zoom.min_x) \
			* zoom.scale_x) / 2;
			data->points[y][x].iso_y += (800 - (zoom.max_y - zoom.min_y) \
			* zoom.scale_y) / 2;
			ft_init_ratio(data, &ratio, y, x);
			data->points[y][x].iso_y -= data->points[y][x].z * zoom.scale_y \
			* ratio;
			x++;
		}
		y++;
	}
}

void	ft_set_min_max(t_data *data, int y, int x, t_zoom *zoom)
{
	if (data->points[y][x].iso_x < (*zoom).min_x)
		(*zoom).min_x = data->points[y][x].iso_x;
	if (data->points[y][x].iso_x > (*zoom).max_x)
		(*zoom).max_x = data->points[y][x].iso_x;
	if (data->points[y][x].iso_y < (*zoom).min_y)
		(*zoom).min_y = data->points[y][x].iso_y;
	if (data->points[y][x].iso_y > (*zoom).max_y)
		(*zoom).max_y = data->points[y][x].iso_y;
}

void	ft_draw_lines(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(data->points[y][x], data->points[y][x + 1], data);
			if (y < data->height - 1)
				ft_bresenham(data->points[y][x], data->points[y + 1][x], data);
			x++;
		}
		y++;
	}
}
