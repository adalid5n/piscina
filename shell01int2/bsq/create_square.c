void	create_square(char **map, int row, int col)
{
	int	l;
	
	l = ;	//tendriamos que conseguir la length de la row
	while (col < l)
	{
		if (is_safe(row, col + 1))
			col++;
		else
			break;
	}
	
}

void	print_map(char **map, char *list)
{
	int	row;
	int start;
	int end;
	int i;
	int j;
	
	i = 0;
	start = list[1]
	end = list [3];
	len = list[3] - list[1];
	j = 0;
	while (map[i][j] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i >= row && i <= row + len) && (j >= start && j <= end))
					write(1, "x", 1);
			else
				write(1, %map[i][j], 1);
			j++;
		}
		i++;
	}
}
