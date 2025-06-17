/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:34:45 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/11 16:44:45 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				counter;
	char			*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (*buf[fd] != '\0')
		line = ft_strjoin (line, buf[fd]);
	while (ft_newline_counter(line) == -1)
	{
		counter = read (fd, buf[fd], BUFFER_SIZE);
		if (counter < 0)
		{
			buf[fd][0] = '\0';
			return (free(line), NULL);
		}
		if (counter == 0)
			break ;
		buf[fd][counter] = '\0';
		line = ft_strjoin(line, buf[fd]);
	}
	line = ft_line_builder(line);
	ft_clean_stash(buf[fd]);
	return (line);
}
int main(void)
{
	int	i;
	int	fd1 = open("text1.txt", O_RDONLY);
	int	fd2 = open("text2.txt", O_RDONLY);
	int	fd3 = open("text3.txt", O_RDONLY);
	char *line;

	i = 3;

	while (i--)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}