/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:41:21 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/26 02:02:55 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx/mlx.h"
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
#endif