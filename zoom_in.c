/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:11:02 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 03:09:00 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calculate_zoom_center(t_data *data, t_zoom *zoom)
{
	int	i;
	int	j;

	zoom->center_x = 0.0;
	zoom->center_y = 0.0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			zoom->center_x += data->points[i][j].iso_x;
			zoom->center_y += data->points[i][j].iso_y;
			j++;
		}
		i++;
	}
	zoom->center_x /= (data->height * data->width);
	zoom->center_y /= (data->height * data->width);
}

static void	zoom_points(t_data *data, double factor)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x *= factor;
			data->points[i][j].iso_y *= factor;
			j++;
		}
		i++;
	}
}

static void	calculate_zoom_center_after_zoom(t_data *data, t_zoom *zoom)
{
	int	i;
	int	j;

	zoom->center_x_after_zoom = 0.0;
	zoom->center_y_after_zoom = 0.0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			zoom->center_x_after_zoom += data->points[i][j].iso_x;
			zoom->center_y_after_zoom += data->points[i][j].iso_y;
			j++;
		}
		i++;
	}
	zoom->center_x_after_zoom /= (data->height * data->width);
	zoom->center_y_after_zoom /= (data->height * data->width);
}

static void	translate_points(t_data *data, t_zoom *zoom)
{
	int	i;
	int	j;

	zoom->translate_x = zoom->center_x - zoom->center_x_after_zoom;
	zoom->translate_y = zoom->center_y - zoom->center_y_after_zoom;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x += zoom->translate_x;
			data->points[i][j].iso_y += zoom->translate_y;
			j++;
		}
		i++;
	}
}

void	ft_zoom_in(t_data *data)
{
	t_zoom	zoom;
	double	factor;

	factor = 1.1;
	calculate_zoom_center(data, &zoom);
	zoom_points(data, 1.10);
	calculate_zoom_center_after_zoom(data, &zoom);
	translate_points(data, &zoom);
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	ft_fill_image_black(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
}
