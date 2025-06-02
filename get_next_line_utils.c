/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:37:15 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/02 16:27:53 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
ft_newline_counter(char *line)
{
	int i;
	if (!line)
		return (-1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}
size_t	ft_strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s3 = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[i])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[j + i] = '\0';
	free(s1);
	return (s3);
}
char	*ft_line_builder(char *s)
{
	int		i;
	int		line_size;
	char	*line;
	
	if (!s || !*s)
		return (NULL);
	i = 0;
	line_size = ft_newline_counter (s);
	if (line_size == -1)
		line_size = ft_strlen(s) - 1;
	line = malloc(sizeof(char) * line_size + 2);
	if (!line)
		return (NULL);
	while (s[i] != '\n' && s[i])
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	free (s);
	return (line);
}

void	ft_clean_stash(char *stash)
{
	
}