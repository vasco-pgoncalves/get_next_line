/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascopinto <vascopinto@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:17:01 by vascopinto        #+#    #+#             */
/*   Updated: 2025/05/29 16:55:19 by vascopinto       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				counter;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
    if(*buf != '\0')
        line = ft_strjoin (line, buf);
    while (ft_newline_counter(line) == -1)
    {
        line = read (fd, buf, BUFFER_SIZE);
        
    }
}