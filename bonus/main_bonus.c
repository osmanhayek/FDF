/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:46:42 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 23:18:22 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	ft_deallocate(data);
	exit(0);
}

void	ft_fill_image_black(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 800)
		{
			my_mlx_put_pixel_image(data, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	else if (keycode == 49)
		ft_zoom_in(data);
	else if (keycode == 32)
	{
		rotate_object(data);
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		ft_fill_image_black(data);
		ft_draw_lines(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, \
		data->image, 0, 0);
	}
	else if (keycode == 12)
		ft_zoom_out(data);
	else if (keycode == 13)
		ft_translate_w(data);
	else if (keycode == 0)
		ft_translate_a(data);
	else if (keycode == 1)
		ft_translate_s(data);
	else if (keycode == 2)
		ft_translate_d(data);
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
	data->image = mlx_new_image(data->mlx_ptr, 1000, 800);
	data->image_data = mlx_get_data_addr(data->image, \
	&data->bits_per_pixel, &data->size_line, &data->endian);
	mlx_hook(data->mlx_window, 17, 0, close_window, data);
	ft_fill_image_black(data);
	ft_isometric(data);
	apply_zoom_and_shift(data);
	ft_draw_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->image, 0, 0);
	mlx_key_hook(data->mlx_window, key_press, data);
	mlx_loop(data->mlx_ptr);
	ft_deallocate(data);
	return (0);
}
