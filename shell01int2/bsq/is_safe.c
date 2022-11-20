/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouali <mouali@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:09:30 by mouali            #+#    #+#             */
/*   Updated: 2022/08/30 21:20:28 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define X 27
#define Y 9

void	print_map(char **map, int *list)
{
	int	len;
	int	i;
	int	j;
	int	start_row;

	start_row = list[0];
	len = list[3] - list[1];
	i = 0;
	while (i < Y)
	{
		j = 0;
		while (j < X)
		{
			if ((i >= start_row && i <= start_row + len)
				&& (j >= list[1] && j <= list[3]))
				write(1, "x", 1);
			else
				write(1, &map[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	*store_or_remove(int sol[4], int row, int start_col, int end_col)
{
	if ((end_col - start_col) > (sol[3] - sol[1]))
	{
		sol[0] = row;
		sol[1] = start_col;
		sol[2] = row;
		sol[3] = end_col;
	}
	return (sol);
}

int	is_safe(char **map, int row, int start_col, int end_col)
{
	int	length;
	int	aux_col;
	int	aux_row;

	aux_col = end_col;
	aux_row = row;
	length = end_col - start_col;
	while (length >= 0)
	{
		if (map[aux_row][end_col] == 'o' || aux_row >= Y)
			return (0);
		aux_row++;
		length--;
	}
	aux_row--;
	length = end_col - start_col;
	while (length >= 0)
	{
		if (map[aux_row][end_col] == 'o')
			return (0);
		end_col--;
		length--;
	}
	return (1);
}

int	create_square(char **map, int row, int start_col, int col)
{
	while (col < X - 1)
	{
		if (is_safe(map, row, start_col, col + 1))
			col++;
		else
			break ;
	}
	return (col);
}

void	solve(char **map)
{
	int	sol[4] = {0, 0, 0, 0};
	int	row;
	int	col;
	int	start_col;

	row = -1;
	while (++row < Y)
	{
		col = -1;
		while (++col < X)
		{
			if (map[row][col] != 'o')
			{
				start_col = col;
				col = create_square(map, row, start_col, col);
				store_or_remove(sol, row, start_col, col);
			}
		}
	}
	print_map(map, sol);
}

int	main(void)
{
	int	i = -1;
	int	j;
	char	**map;

	map = (char **)malloc(Y * sizeof(char *));
	if (!map)
		exit (1);
	while (++i < X)
	{
		map[i] = (char *)malloc(X * sizeof(char));
		if (!map[i])
			exit (1);
	}
	i = -1; 
	while (++i < Y)
	{
		j = -1;
		while (++j < X)
			map[i][j] = '.';
	}
	map[1][4] = 'o';
	map[4][4] = 'o';
	map[7][6] = 'o';
	map[8][2] = 'o';
	map[2][12] = 'o';
	map[5][15] = 'o';
	map[7][21] = 'o';
	map[8][10] = 'o';
	
	solve(map);	

	i = -1;
	
	while (++i < Y)
		free(map[i]);
	free(map);
	
	return (0);
}
