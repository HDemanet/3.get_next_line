/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:04:52 by hdemanet          #+#    #+#             */
/*   Updated: 2024/05/07 11:37:27 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr_copy_reverse(char *s, int c);
char	*ft_strchr_copy(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);

char	*ft_free(char **tmp);
char	*next_line_data(char *ld);
char	*get_line_from_buffer(char *line_data);
char	*read_data_from_file(char *line_data, int fd);
char	*get_next_line(int fd);

#endif