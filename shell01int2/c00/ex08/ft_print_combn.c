/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:42 by aguzman-          #+#    #+#             */
/*   Updated: 2022/09/01 16:32:54 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_num(int a, int b, int c)
{
	char	ca;
	char	cb;
	char	cc;

	ca = a + '0';
	cb = b + '0';
	cc = c + '0';
	write(1, &ca, 1);
	write(1, &cb, 1);
	write(1, &cc, 1);
	if (a != 7)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ft_print_num(a, b, c);
				c++;
			}
			b++;
		}	
		a++;
	}
}
