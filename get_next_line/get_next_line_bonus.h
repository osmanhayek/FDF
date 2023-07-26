/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:20:00 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/11 23:29:42 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void			create_res(char **res, int fd);
char			*clean_res(char *res);
char			*get_next_line(int fd);
unsigned int	ft_strlen(const char *str);
char			*ft_append(char *s1, const char *s2);
unsigned int	founded_next_line(char *res);
unsigned int	len_to_next_line(char *str);
char			*find_line(char *res);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);

#endif