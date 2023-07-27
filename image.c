/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:28:14 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 02:31:14 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_put_pixel_image(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->image_data + (y * data->size_line + x * \
	(data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
