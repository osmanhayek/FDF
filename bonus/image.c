/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:28:14 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 22:33:55 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_put_check_image(t_data *data, int x, int y, t_point start)
{
	if (x > 950 || y > 750 || y < 0 || x < 0)
		return ;
	else
		my_mlx_put_pixel_image(data, x, y, start.color);
}

void	my_mlx_put_pixel_image(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->image_data + (y * data->size_line + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
