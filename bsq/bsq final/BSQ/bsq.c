/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:50:47 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/31 17:21:59 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char *argv[])
{
	int			i;
	int			ii;
	int			no_argc;
	t_files		*files;
	t_square	*square;

	no_argc = 0;
	if (argc == 1)
	{
		(void)argv;
		files = ft_read_map_files();
		argv = files->names;
		argc = files->num;
		no_argc = 1;
	}
	i = 0;
	if (no_argc == 1)
		--i;
	while (++i < argc)
	{
		if (ft_valid_map_file(argv[i]))
		{
			--g_col;
			ft_init_map();
			free(g_map_str);
			square = ft_find_max_square();
			ft_print_map(square);
			free(square);
			ii = -1;
			while (++ii < g_row)
				free(g_matrix_map[ii]);
			free(g_matrix_map);
		}
		else
			write(1, "map error\n", 10);
		write(1, "\n", 1);
	}
	return (0);
}
