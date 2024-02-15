/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by hclaude           #+#    #+#             */
/*   Updated: 2024/02/15 05:07:43 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	is_backslash(char *buffer, unsigned int *last_newline_index)
{
	unsigned int	i;

	i = *last_newline_index;
	while (buffer[i])
	{
		if ('\n' == buffer[i])
		{
			*last_newline_index = 0;
			return (i);
		}
		i++;
	}
	*last_newline_index = i;
	return (-1);
}

static void	replace(char **buffer, int index)
{
	char	*src;
	char	*dest;

	src = *buffer + index + 1;
	dest = *buffer;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

static int	read_and_get(int fd, char **buffer,
		unsigned int *last_newline_index)
{
	char	*new_str;
	char	*new_buffer;
	ssize_t	n_read;

	new_buffer = NULL;
	new_str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!new_str)
		return (1);
	while (is_backslash(*buffer, last_newline_index) == -1)
	{
		n_read = read(fd, new_str, BUFFER_SIZE);
		if (n_read == -1)
			return (free(new_str), free(new_buffer), -1);
		else if (n_read == 0)
			return (free(new_str), 1);
		new_buffer = ft_strjoin(*buffer, new_str);
		free(*buffer);
		*buffer = new_buffer;
		if (!*buffer)
			return (free(new_str), -1);
		ft_bzero(new_str, BUFFER_SIZE);
	}
	return (free(new_str), 0);
}

static char	*get_next_line_part2(int fd, char **buffer,
		unsigned int *last_newline_index)
{
	int		index;
	char	*return_line;

	if (read_and_get(fd, buffer, last_newline_index) == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	index = is_backslash(*buffer, last_newline_index);
	if (index != -1)
	{
		return_line = ft_strndup(*buffer, index + 1);
		replace(buffer, index);
	}
	else
	{
		if (*buffer[0] == '\0')
			return_line = NULL;
		else
			return_line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (return_line);
}

char	*get_next_line(int fd)
{
	static char			*buffer[1024];
	static unsigned int	last_newline_index[1024] = {0};

	if (fd < 0 || BUFFER_SIZE < 0 || fd >= 1024)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
	}
	return (get_next_line_part2(fd, &buffer[fd], &last_newline_index[fd]));
}
