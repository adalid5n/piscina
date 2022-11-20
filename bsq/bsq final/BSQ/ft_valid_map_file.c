/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:41:36 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/08/31 18:42:19 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_valid_size(char *line_char, int cont_col)
{
	if (cont_col != g_col)
		return (0);
	if (line_char[0] != '\n' && line_char[0] != g_empty
		&& line_char[0] != g_obstacle && line_char[0] != g_full)
		return (0);
	return (1);
}

int	ft_valid_line(char *line_char)
{
	if (line_char[0] != '\n' && line_char[0] != g_empty
		&& line_char[0] != g_obstacle && line_char[0] != g_full)
		return (0);
	return (1);
}

int	ft_valid_col(int fd)
{
	int		b;
	int		r;
	int		empty;
	int		rows;
	int		cont;
	char	*line;

	b = 1;
	r = 1;
	g_col = 0;
	empty = 0;
	while (b)
	{
		++g_col;
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			ft_error("malloc error\n");
		read(fd, line, 1);
		if (!ft_valid_line(line))
		{
			free(line);
			return (0);
		}
		if (line[0] == '\n')
			b = 0;
		if (line[0] == g_empty)
			empty = 1;
		free(line);
	}
	if (g_col < 1)
		return (0);
	if (g_row == 1)
		return (empty);
	cont = 0;
	rows = g_row - 1;
	while (r && rows)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			ft_error("malloc error\n");
		r = read(fd, line, 1);
		++cont;
		if (!ft_valid_line(line))
		{
			free(line);
			return (0);
		}
		if (line[0] == '\n')
		{
			if (!ft_valid_size(line, cont))
			{
				free(line);
				return (0);
			}
			cont = 0;
			--rows;
		}
		if (line[0] == g_empty)
			empty = 1;
		free(line);
	}
	return (empty);
}

char	*ft_read_info(char *file, int fd)
{
	int		size;
	int		b;
	char	*info;

	size = 0;
	b = 1;
	while (b)
	{
		++size;
		info = (char *)malloc(1 * sizeof(char));
		read(fd, info, 1);
		if (info[0] == '\n')
			b = 0;
		free(info);
	}
	info = (char *)malloc(size * sizeof(char));
	fd = open(file, O_RDONLY);
	read(fd, info, size);
	close(fd);
	return (info);
}

void aux_ft_valid( *file, g_row, g_col, )
{
	:wq

}

int	ft_valid_map_file(char *file)
{
	int		fd;
	int		size;
	char	*info;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	info = ft_read_info(file, fd);
	size = ft_strlen(info);
	if (size < 5)
	{
		free(info);
		return (0);
	}
	ft_init_globals(info[size - 4], info[size - 3], info[size - 2]);
	if (info[size - 1] != '\n' || !ft_valid_char()
		|| !ft_valid_num(info, size - 5) || !ft_valid_col(fd))
	{
		free(info);
		return (0);
	}
	close(fd);
	free(info);
	g_map_str = (char *)malloc((g_row * g_col) * sizeof(char));
	if (!g_map_str)
	{
		free(g_map_str);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, g_map_str, size);
	read(fd, g_map_str, g_row * g_col);
	close(fd);
	return (1);
}
