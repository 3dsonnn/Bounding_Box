/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Updated by: efinda (Enhanced version)             +#+  +:+       +#+        */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * extract_line:
 *   Allocates and returns a new string containing the next line from s.
 *   The returned line includes the newline character if found.
 *   Returns NULL if s is NULL or empty.
 */
static char	*extract_line(const char *s)
{
	int		i;
	char	*line;

	if (!s || *s == '\0')
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;  // Include the newline character.
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	// Copy i+1 characters (including the terminating '\0')
	ft_strlcpy(line, s, i + 1);
	return (line);
}

/*
 * remove_extracted_line:
 *   Given the buffer s and the length (len) of the extracted line,
 *   allocates a new string containing the remainder of s and frees s.
 *   Returns NULL if there is no remainder.
 */
static char	*remove_extracted_line(char *s, int len)
{
	int		total_len;
	char	*new_buf;

	if (!s)
		return (NULL);
	total_len = ft_strlen(s);
	if (len >= total_len)
	{
		free(s);
		return (NULL);
	}
	new_buf = ft_substr(s, len, total_len - len);
	free(s);
	return (new_buf);
}

/*
 * get_next_line:
 *   Reads from file descriptor fd until a newline is found (or EOF),
 *   returning the next line as a newly allocated string.
 *   Uses a static array to hold leftover data between calls.
 */
char	*get_next_line(int fd)
{
	static char	*fd_buffer[FD_MAX];
	char		*temp;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Allocate temporary buffer for reading.
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	// Read until a newline is encountered or no more bytes are read.
	while (bytes_read > 0 && !ft_strchr(fd_buffer[fd], '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			if (fd_buffer[fd])
			{
				free(fd_buffer[fd]);
				fd_buffer[fd] = NULL;
			}
			return (NULL);
		}
		temp[bytes_read] = '\0';
		// Append the newly read data to fd_buffer[fd].
		fd_buffer[fd] = ft_strjoin_free(fd_buffer[fd], temp);
	}
	free(temp);
	// Extract the next line from the buffer.
	line = extract_line(fd_buffer[fd]);
	// Update the buffer by removing the extracted line.
	if (line)
		fd_buffer[fd] = remove_extracted_line(fd_buffer[fd], ft_strlen(line));
	return (line);
}
