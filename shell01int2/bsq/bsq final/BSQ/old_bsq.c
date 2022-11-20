
#include "bsq.h"

int g_n;
// int g_row;
// int g_col;
// char full;
// char empty;
// char obstacle;

// char map[9][9] = {
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', 'o', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', 'o', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', 'o', '.', '.', '.', '.', '.'},
// 	{'.', '.', '.', '.', '.', '.', '.', '.', '.'}
// };

// void	ft_init_map(char **map)
// {	
// }


// void	ft_solve_map()
// {
// }

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
	(void)argv;
		argv = ft_read_map_files();
		argc = ft_num_files(*argv[]);
	}
	// while (--argc)
	// {
	// 	ft_valid_map_file(argv[argc]);
	// 	ft_inti_map();
	// 	ft_find_max_square();
	// 	ft_print_square();
	// }

	//
	// int	aux;
	// char **map;

	// g_n = 9;
	// aux = g_n;
	// map = (char **)malloc(g_n * sizeof(char *));
	// if (!map)
	// 	ft_error("malloc error\n");
	// while (aux--)
	// {
	// 	map[aux] = (char *)malloc(g_n * sizeof(char));
	// 	if (!map[aux])
	// 		ft_error("malloc error\n");
	// }
	// //
	// // ft_init_map(map);
	// //

	// aux = g_n;
	// while (--aux)
	// 	free(map[aux]);
	// free(map);
	while (argc--)
		free(argv[argc]);
	free(argv);
	// return (0);
}