/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpinto-g <vpinto-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:43:31 by vpinto-g          #+#    #+#             */
/*   Updated: 2025/06/02 16:20:20 by vpinto-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>


char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
ft_newline_counter(char *line);
char	*ft_line_builder(char *s);

#endif