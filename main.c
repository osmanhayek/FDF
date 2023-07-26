/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:42 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/26 03:05:19 by ohayek           ###   ########.fr       */
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

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 53)
		close_window(data);
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
	mlx_loop(data->mlx_ptr);
	ft_deallocate(data);
}
