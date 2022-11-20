/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:04:17 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/30 19:44:10 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_map(char **map, int row, int col, char *list)
{
	int	len;
	int	i;
	int	j;
	int	start_row;

	start_row = list[0] - '0';
	len = (list[3] - '0') - (list[1] - '0');
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if ((i >= start_row && i <= start_row + len)
				&& (j >= (list[1] - '0') && j <= (list[3] - '0')))
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
