/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:00:15 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 22:31:39 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_set_s(t_point *start, t_point *end, t_bresenham *algo)
{
	if ((*start).iso_x < (*end).iso_x)
		(*algo).sx = 1;
	else
	{
		(*algo).sx = -1;
	}
	if ((*start).iso_y < (*end).iso_y)
		(*algo).sy = 1;
	else
		(*algo).sy = -1;
	(*algo).err = (*algo).dx - (*algo).dy;
}

int	my_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	apply_zoom_and_shift(t_data *data)
{
	t_zoom	zoom;
	int		y;
	int		x;

	zoom.max_x = 0;
	zoom.min_x = 0;
	zoom.max_y = 0;
	zoom.min_y = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			ft_set_min_max(data, y, x, &zoom);
			x++;
		}
		y++;
	}
	zoom.scale_x = ((600)) / (zoom.max_x - zoom.min_x);
	zoom.scale_y = ((500)) / (zoom.max_y - zoom.min_y);
	ft_shift_zoom(data, zoom);
}

void	ft_isometric(t_data *data)
{
	double	iso_angle;
	int		x;
	int		y;

	iso_angle = 45.45 * (M_PI / 180.0);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->points[y][x].iso_x = (x - y) * cos(iso_angle);
			data->points[y][x].iso_y = (y + x) * sin(iso_angle);
			x++;
		}
		y++;
	}
}

void	ft_bresenham(t_point start, t_point end, t_data *data)
{
	t_bresenham	algo;
	int			x;
	int			y;
	int			e2;

	algo.dx = my_abs((int)end.iso_x - (int)start.iso_x);
	algo.dy = my_abs((int)end.iso_y - (int)start.iso_y);
	ft_set_s(&start, &end, &algo);
	x = (int)start.iso_x;
	y = (int)start.iso_y;
	while (x != (int)end.iso_x || y != (int)end.iso_y)
	{
		ft_put_check_image(data, x, y, start);
		e2 = 2 * algo.err;
		if (e2 > -algo.dy)
		{
			algo.err -= algo.dy;
			x += algo.sx;
		}
		if (e2 < algo.dx)
		{
			algo.err += algo.dx;
			y += algo.sy;
		}
	}
}
