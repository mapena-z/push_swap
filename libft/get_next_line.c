/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 01:46:19 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/06 17:15:51 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *str)
{
	char	*new_str_line;
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		new_str_line = ft_strjoin(str, buffer);
		free(str);
		str = new_str_line;
	}
	free(buffer);
	return (str);
}

static char	*get_line(char *str)
{
	int		len;
	char	*new_str;

	if (!str || !str[0])
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		new_str = ft_substr(str, 0, len + 1);
	else
		new_str = ft_substr(str, 0, len);
	return (new_str);
}

static char	*get_rest(char *str)
{
	int		len;
	char	*rest;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (!str[len])
	{
		free(str);
		return (NULL);
	}
	rest = ft_substr(str, len + 1, ft_strlen(str) - len - 1);
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (!str[fd])
		return (NULL);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (str[fd] = NULL, NULL);
	if (!str[fd][0])
	{
		free(str[fd]);
		return (str[fd] = NULL, NULL);
	}
	line = get_line(str[fd]);
	str[fd] = get_rest(str[fd]);
	return (line);
}
