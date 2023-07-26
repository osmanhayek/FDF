/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:42 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/26 15:33:42 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	ft_deallocate(data);
	exit(0);
}

void rotate_object(t_data *data)
{
    // Step 1: Calculate the center of the object
    double center_x = 0.0;
    double center_y = 0.0;
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            center_x += data->points[i][j].iso_x;
            center_y += data->points[i][j].iso_y;
        }
    }
    center_x /= (data->height * data->width);
    center_y /= (data->height * data->width);

    // Step 2: Apply the rotation around the center
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            // Translate point to the origin
            double translated_x = data->points[i][j].iso_x - center_x;
            double translated_y = data->points[i][j].iso_y - center_y;

            // Perform 90-degree rotation
            double temp_x = translated_y;
            double temp_y = -translated_x;

            // Translate back to the original position
            data->points[i][j].iso_x = temp_x + center_x;
            data->points[i][j].iso_y = temp_y + center_y;
        }
    }
}

int	key_press(int keycode, t_data *data)
{

	if (keycode == 53)
		close_window(data);
if (keycode == 119) // Assuming keycode 119 corresponds to the zoom-out action.
{
    // Step 1: Calculate the center of the object before zooming
    double center_x = 0.0;
    double center_y = 0.0;
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            center_x += data->points[i][j].iso_x;
            center_y += data->points[i][j].iso_y;
        }
    }
    center_x /= (data->height * data->width);
    center_y /= (data->height * data->width);

    // Step 2: Apply the zoom factor and adjust the points
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            data->points[i][j].iso_x *= 1.2;
            data->points[i][j].iso_y *= 1.2;
        }
    }

    // Step 3: Calculate the center of the object after zooming
    double center_x_after_zoom = 0.0;
    double center_y_after_zoom = 0.0;
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            center_x_after_zoom += data->points[i][j].iso_x;
            center_y_after_zoom += data->points[i][j].iso_y;
        }
    }
    center_x_after_zoom /= (data->height * data->width);
    center_y_after_zoom /= (data->height * data->width);

    // Step 4: Calculate the translation required to keep the object centered
    double translate_x = center_x - center_x_after_zoom;
    double translate_y = center_y - center_y_after_zoom;

    // Step 5: Apply the reverse translation to keep the object centered
    for (int i = 0; i < data->height; i++)
    {
        for (int j = 0; j < data->width; j++)
        {
            data->points[i][j].iso_x += translate_x;
            data->points[i][j].iso_y += translate_y;
        }
    }

    // Clear the window and redraw the lines
    mlx_clear_window(data->mlx_ptr, data->mlx_window);
    ft_draw_lines(data);
	
	}
	else if (keycode == 32)
	{
		rotate_object(data);
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		ft_draw_lines(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fdf <your_test_map>\n", 2);
		exit(1);
	}
	ft_init_data(&data, av);
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, 1000, 800, "Fdf");
	mlx_hook(data->mlx_window, 17, 0, close_window, data);
	mlx_hook(data->mlx_window, 2, 0, key_press, data);
	ft_isometric(data);
	apply_zoom_and_shift(data);
	ft_draw_lines(data);
	mlx_key_hook(data->mlx_window, key_press, data);
	mlx_loop(data->mlx_ptr);
	ft_deallocate(data);
	return (0);
}