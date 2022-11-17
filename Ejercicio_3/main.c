/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:26:13 by jvasquez          #+#    #+#             */
/*   Updated: 2022/11/17 02:14:52 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

int	line_count(char *file)
{
	int	fd;
	char *line;
	int count;

	fd = open(file, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;	
	}
	close(fd);
	return (count);
}


char *rnd_line(int opc, int fd)
{
	char	*linea;
	int	i;

	i = rand() % opc;
	linea = get_next_line(fd);
	while (i--)
	{
		free(linea);
		linea = get_next_line(fd);
	}
	return (linea);
}

void print_wocr(char *linea)
{
	int	i;
	char c;

	c = 32;
	i = -1;
	while (linea[++i] != '\n')
		write(1, &linea[i], 1);
	write(1, &c, 1);
	free(linea);
}

int	frase(int v)
{
	int		fd[3];
	int		i;
	char	**files;

	files = malloc(sizeof(char *) * 3);
	files[0] = malloc(sizeof(char) * 14);
	files[1] = malloc(sizeof(char) * 12);
	files[2] = malloc(sizeof(char) * 15);
	strcpy(files[0], "src/adjetivos");
	strcpy(files[1], "src/sujetos");
	strcpy(files[2], "src/predicados");
	i = -1;
	while (++i < 3)
	{
		fd[i] = open(files[i], O_RDONLY);
		srand(v);
		print_wocr(rnd_line(line_count(files[i]), fd[i]));
	}
	printf("\n");
	i = 3;
	while (i--)
	{
		close(fd[i]);
		free (files[i]);
	}
	free(files);
	return (0);
}

int	main(void)
{
	int	i;
	int j;

	i = 5;
	j = (int)&i;
	while (i--)
		frase(j++);
	return (0);
}
