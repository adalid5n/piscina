/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:55:18 by aguzman-          #+#    #+#             */
/*   Updated: 2022/09/01 18:31:22 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		print(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	main(int argc, char **argv)
{
	int	cont;
	int	arg;
	
	arg = 1;
	while (arg < (argc - 1))
	{
		cont = 1;
		while (cont < (argc -1))
		{
			if (ft_strcmp(argv[cont], argv[cont + 1]) > 0)
				ft_swap(&argv[cont], &argv[cont + 1]);
			cont++;
		}
		arg++;
	}
	arg = 1;
	while (arg < argc)
	{
		ft_putstr(argv[arg]);
		write(1, "\n", 1);
		arg++;
	}
	return (0);
}
