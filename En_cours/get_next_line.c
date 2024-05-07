/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:08:12 by hdemanet          #+#    #+#             */
/*   Updated: 2024/05/07 11:45:04 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **tmp)
{
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

char	*next_line_data(char *ld)
{
	char	*new_line_data;
	char	*new_line_ptr;
	int		len;

	new_line_ptr = ft_strchr(ld, '\n');
	if (!new_line_ptr)
	{
		new_line_data = NULL;
		return (ft_free(&ld));
	}
	else
		len = (new_line_ptr - ld) + 1;
	if (!ld[len])
		return (ft_free(&ld));
	new_line_data = ft_strchr_copy(ld, '\n');
	ft_free(&ld);
	if (new_line_data == NULL)
		return (NULL);
	return (new_line_data);
}

char	*get_line_from_buffer(char *line_data)
{
	char	*extracted_line;

	if (!ft_strchr(line_data, '\n'))
	{
		extracted_line = ft_strchr_copy_reverse(line_data, '\0');
		if (!extracted_line)
			return (NULL);
		return (extracted_line);
	}
	extracted_line = ft_strchr_copy_reverse(line_data, '\n');
	if (!extracted_line)
		return (NULL);
	return (extracted_line);
}

char	*read_data_from_file(char *line_data, int fd)
{
	int		nb_bytes_read;
	char	*buffer;

	nb_bytes_read = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&line_data));
	buffer[0] = '\0';
	while (nb_bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		nb_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes_read > 0)
		{
			buffer[nb_bytes_read] = '\0';
			line_data = ft_strjoin(line_data, buffer);
		}
	}
	free(buffer);
	if (nb_bytes_read == -1)
		return (ft_free(&line_data));
	return (line_data);
}

char	*get_next_line(int fd)
{
	static char	*line_data;
	char		*line_data_extracted;

	if (fd < 0)
		return (NULL);
	if (!line_data || (line_data && !ft_strchr(line_data, '\n')))
		line_data = read_data_from_file(line_data, fd);
	if (!line_data)
		return (NULL);
	line_data_extracted = get_line_from_buffer(line_data);
	if (!line_data_extracted)
		return (ft_free(&line_data));
	line_data = next_line_data(line_data);
	return (line_data_extracted);
}

/* int main(void)
{
    int 	fd;
	int		line_number;
    char 	*line;

    fd = open("test.txt", O_RDONLY);
	line_number = 1;
    line = get_next_line(fd); 
	while (line != NULL)
    {
        printf("Line %d : %s\n", line_number++, line);
        line = get_next_line(fd);
    }
	close(fd);
	return (0);
} */
