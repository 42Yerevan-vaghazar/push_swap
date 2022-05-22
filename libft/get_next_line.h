/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:49:21 by vaghazar          #+#    #+#             */
/*   Updated: 2022/03/26 20:53:21 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		free_arr(char *str);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(char *src, char *str_for_free);
char	*ft_substr(char const *src, unsigned int start, size_t len);
int		ft_strchr(const char *s, int c);
int		read_line(char **tmp_line, int fd);

#endif