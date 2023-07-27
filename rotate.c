/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:59:55 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 04:12:17 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_center(t_data *data, double *center_x, double *center_y)
{
	int	i;
	int	j;

	*center_x = 0.0;
	*center_y = 0.0;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			*center_x += data->points[i][j].iso_x;
			*center_y += data->points[i][j].iso_y;
			j++;
		}
		i++;
	}
	*center_x /= (data->height * data->width);
	*center_y /= (data->height * data->width);
}

void	translate_to_center(t_data *data, double center_x, double center_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x -= center_x;
			data->points[i][j].iso_y -= center_y;
			j++;
		}
		i++;
	}
}

void	rotate_points(t_data *data)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			temp = data->points[i][j].iso_x;
			data->points[i][j].iso_x = data->points[i][j].iso_y;
			data->points[i][j].iso_y = -temp;
			j++;
		}
		i++;
	}
}

void	translate_back(t_data *data, double center_x, double center_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x += center_x;
			data->points[i][j].iso_y += center_y;
			j++;
		}
		i++;
	}
}

void	rotate_object(t_data *data)
{
	double	center_x;
	double	center_y;

	calculate_center(data, &center_x, &center_y);
	translate_to_center(data, center_x, center_y);
	rotate_points(data);
	translate_back(data, center_x, center_y);
}
