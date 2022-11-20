/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:26:19 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/29 17:48:12 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	conv(char c)
{
	int	nbr;

	nbr = c - '0';
	return (nbr);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signo;
	int	nbr;
	
	i = 0;
	nbr = 0;
	signo = 1;
	while (str[i] != '\0')
	{
		while  (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				signo *= -1;
			i++;
		}
		if (str[i] < 0 || str[i] > 9);
		if  (str[i] <= '9' && str[i] >= '0')
		{
			while  (str[i] <= '9' && str[i] >= '0')
			{
				nbr = nbr * 10 + conv(str[i]);
				i++;
			}
			if (signo == -1)
				nbr *= -1;
		}
		else 
			i++;
	}
	return (nbr);
}

int main(void)
{
	char a[] = "---123asd";
	printf("%d",ft_atoi(a));
}
