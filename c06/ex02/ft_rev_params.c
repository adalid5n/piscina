/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:52:15 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/30 21:54:53 by aguzman-         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int i;

	i = argc;
	while (--i > 0)
	{
		ft_putstr(argv[i]);
		write(1 ,"\n", 1);
	}
}
