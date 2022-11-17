/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:30:24 by jvasquez          #+#    #+#             */
/*   Updated: 2022/11/16 22:53:28 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
ssize_t	ft_bufjoin(char **buf, int fd);
void	ft_cleanbuf(char **buf);
char	*ft_getline(char **buf, int fd);
char	*ft_fillbuf(ssize_t *size, int fd);
void	*ft_strfree(char **buf);
int		ft_strlen(char *str);
#endif
