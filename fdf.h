/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:41:21 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/27 04:10:51 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "miniliblx/minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	double			z;
	unsigned int	color;
	double			iso_x;
	double			iso_y;
}t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*image;
	char	*image_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	t_point	**points;
}t_data;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}t_bresenham;

typedef struct s_zoom
{
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	scale_x;
	double	scale_y;
	double	center_x;
	double	center_y;
	double	center_x_after_zoom;
	double	center_y_after_zoom;
	double	translate_x;
	double	translate_y;
}t_zoom;

int		ft_atoi_base(const char *str, int str_base);
int		ft_count(const char *str, char c);
void	ft_init_data(t_data **data, char **av);
void	free_split(char **splitted);
void	ft_deallocate(t_data *data);
void	ft_bresenham(t_point start, t_point end, t_data *data);
void	apply_zoom_and_shift(t_data *data);
void	ft_isometric(t_data *data);
void	ft_shift_zoom(t_data *data, t_zoom zoom);
void	ft_set_min_max(t_data *data, int y, int x, t_zoom *zoom);
void	ft_draw_lines(t_data *data);
void	my_mlx_put_pixel_image(t_data *data, int x, int y, int color);
void	ft_zoom_in(t_data *data);
void	ft_fill_image_black(t_data *data);
void	ft_zoom_out(t_data *data);
void	ft_translate_w(t_data *data);
void	ft_translate_a(t_data *data);
void	ft_translate_s(t_data *data);
void	ft_translate_d(t_data *data);
void	rotate_object(t_data *data);
#endif