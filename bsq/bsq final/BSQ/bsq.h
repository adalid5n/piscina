#ifndef BSQ_H
# define BSQ_H

# include<stdio.h>
# include <fcntl.h>
# include<unistd.h>
# include <stdlib.h>

//#define malloc(x)	NULL

int		g_n;
int		g_row;
int		g_col;
char	g_full;
char	g_empty;
char	g_obstacle;

char	*g_map_str;
char	**g_matrix_map;

typedef	struct	s_files {
	int		num;
	char	**names;
}				t_files;

typedef	struct	s_square {
	int	row;
	int	start_col;
	int	end_col;
}				t_square;

/*----*/
void			ft_error(char *str);

int				ft_strlen(char *str);

int				ft_valid_num(char *num, int size);

int				ft_valid_char();

void			ft_init_globals(char e, char o, char f);

/*----*/
struct s_files	*ft_read_map_files();

/*----*/
int				ft_valid_map_file(char *file);

/*----*/
void			ft_init_map();

/*----*/
void			ft_print_map(t_square *square);

/*----*/
struct s_square	*ft_find_max_square();

#endif