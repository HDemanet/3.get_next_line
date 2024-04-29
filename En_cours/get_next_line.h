/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:08:19 by hdemanet          #+#    #+#             */
/*   Updated: 2024/04/29 16:10:35 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10 // si on oublie de definir la taille du buffer a la compilation
#endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *backup);
char	*ft_get_line(char *backup);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_remove_line(char *backup);

#endif