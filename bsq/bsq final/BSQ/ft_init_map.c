#include "bsq.h"

void    ft_init_map()
{
	int		i;
	int		j;
	int		k;
	// printf("-------->NUM ROW AND COL: %d %d\n", g_row, g_col);
	g_matrix_map = (char **)malloc((g_row + 1) * sizeof(char *));
	if (!g_matrix_map)
		ft_error("malloc_error\n");
	i = 0;
	while (i < g_col + 1)
	{
		g_matrix_map[i] = (char *)malloc((g_col + 1) * sizeof(char));
		if (!g_matrix_map[i])
			ft_error("malloc_error\n");
		++i;
	}
	// printf("%s", g_map_str);
	k = 0;
	i = 0;
	// printf("%d, %d\n", g_row, g_col);
	while (i < g_row)
	{
		j = 0;
		while(j < g_col + 1)
		{
			// printf("%c", g_map_str[k]);
			if (g_map_str[k] == '\n')
			{
				++k;
				g_matrix_map[i][j] = '\0';
			}
			else
				g_matrix_map[i][j] = g_map_str[k++];
			++j;
		}
		++i;
	}
}