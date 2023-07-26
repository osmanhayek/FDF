/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:59:03 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/25 16:27:31 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	ft_deallocate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->points[i++]);
	free(data->points);
	free(data);
}
