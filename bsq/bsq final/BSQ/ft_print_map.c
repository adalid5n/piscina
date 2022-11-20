/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:26:44 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/31 17:44:47 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_map(t_square *square)
{
	int	i;
	int	j;
	int	size;
	int	start_row;

	start_row = square->row;
	size = square->end_col - square->start_col;
	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j < g_col)
		{
			if ((i >= start_row) && (i <= start_row + size)
				&& (j >= square->start_col) && (j <= square->end_col))
				write(1, &g_full, 1);
			else
				write(1, &g_matrix_map[i][j], 1);
			if (j + 1 < g_col)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
