/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:26:19 by aguzman-          #+#    #+#             */
/*   Updated: 2022/09/01 18:22:20 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	signo;
	int	nbr;

	i = 0;
	nbr = 0;
	signo = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-')
	{
		signo = signo * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}	
	return (nbr * signo);
}

/*int main(void)
{
	char a[] = "	\n	---123-asd";
	printf("%d",ft_atoi(a));
}*/
