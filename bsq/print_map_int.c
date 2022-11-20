/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:04:17 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/30 20:09:57 by aguzman-         ###   ########.fr       */
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

void    ft_print(char **M, int row, int col)
{
    int i = 0;
    while (i < row)
    {
        int j = 0;
        while (j < col)
        {
            printf("%c ", M[i][j]);
            ++j;
        }
        printf("\n");
        ++i;
    }
}

int main(void)
{
	char **M;
	int row;
	int col;

	row = 6;
	col = 6;
    
	M = (char **)malloc(row * sizeof(char *));
	if (!M)
		exit(1);
    int i = 0;
    while (i < col)
    {
        M[i] = (char *)malloc(col * sizeof(char));
        if (!M[i])
            exit(1);
        ++i;
    }
    
    i = 0;
    int k = 0;
    while (i < row)
    {
        int j = 0;
        while(j < col)
        {
            M[i][j] = '.';
            ++j;
        }
        ++i;
    }

	ft_print(M, row, col);
	
	write(1, "================HEHE=============", 30);
	write(1,"\n", 1);
	
	print_map(M, row, col, "1114");

    i = 0;
    while (i < col)
    {
        free(M[i]);
        ++i;
    }
    free(M);
}

