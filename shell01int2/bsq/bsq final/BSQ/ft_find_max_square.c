#include "bsq.h"

void    ft_store_or_remove(t_square *square, int row, int start_col, int end_col)
{
	if (((end_col - start_col) > (square->end_col - square->start_col))
		|| square->end_col == -1 || square->start_col == -1 || square->row == -1)
	{
		square->row = row;
		square->start_col = start_col;
		square->end_col = end_col;
	}
}

int	ft_is_safe(int row, int start_col, int end_col)
{
	int	length;
	int	aux_row;

	aux_row = row;
	length = end_col - start_col;
	while (length >= 0)
	{
		if (g_matrix_map[aux_row][end_col] == 'o' || aux_row >= g_row)
			return (0);
		aux_row++;
		length--;
	}
	aux_row--;
	length = end_col - start_col;
	while (length >= 0)
	{
		if (g_matrix_map[aux_row][end_col] == 'o')
			return (0);
		end_col--;
		length--;
	}
	return (1);
}

int	ft_create_square(int row, int start_col, int end_col)
{
	while (end_col < g_col - 1)
	{
		if (ft_is_safe(row, start_col, end_col + 1))
			end_col++;
		else
			break;
	}
	return (end_col);
}

struct s_square	*ft_find_max_square()
{
	int i;
	int j;
	int start_col;
	t_square *square;

	square = (t_square *)malloc(sizeof(t_square));
	if (!square)
		ft_error("malloc error\n");
	square->start_col = -1;
	square->end_col = -1;
	square->row = -1;
	i = -1;
	// printf("NUM DE ROW %d Y NUM DE COL %d\n", g_row, g_col);
	while (++i < g_row)
	{
		j = -1;
		while (++j < g_col)
		{
			// printf("ROW %d Y COL %d\n", i, j);
			if (g_matrix_map[i][j] != 'o')
			{
				start_col = j;
				j = ft_create_square(i, start_col, j);
				ft_store_or_remove(square, i, start_col, j);
				j = start_col;
			}
		}
	}
	return (square);
}
