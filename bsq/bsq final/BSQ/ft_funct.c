#include "bsq.h"

void    ft_error(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
    exit(1);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		++str;
		++c;
	}
	return (c);
}

int	ft_valid_num(char *num, int size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i <= size)  // falta que empize por ceros
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		n = 10 * n + (num[i] - '0');		
		++i;
	}
	g_row = n;
	//printf("ROW: %d\n", g_row);
	return (1);
}

int	ft_valid_char()
{
	if (g_empty != g_obstacle && g_empty != g_full && g_obstacle != g_full)
		return (1);
	return (0);
}

void	ft_init_globals(char e, char o, char f)
{
	g_empty = e;
	g_obstacle = o;
	g_full = f;
}
