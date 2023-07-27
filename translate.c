/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:30:54 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 03:37:24 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate_w(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_y -= 5.0;
			j++;
		}
		i++;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	ft_fill_image_black(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
}

void	ft_translate_a(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x -= 5.0;
			j++;
		}
		i++;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	ft_fill_image_black(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
}

void	ft_translate_s(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_y += 5.0;
			j++;
		}
		i++;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	ft_fill_image_black(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
}

void	ft_translate_d(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->points[i][j].iso_x += 5.0;
			j++;
		}
		i++;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_window);
	ft_fill_image_black(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
}
