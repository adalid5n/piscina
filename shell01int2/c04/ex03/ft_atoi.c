/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:26:19 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/29 18:27:19 by aguzman-         ###   ########.fr       */
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
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			if ((str[i + 1] < '0' || str[i + 1] > '9') && !(str[i + 1] == '-' || str[i + 1] == '+'))
				return (nbr);
			signo *= -1;
		}
		if  (str[i] <= '9' && str[i] >= '0')
		{
			while  (str[i] <= '9' && str[i] >= '0')
				nbr = nbr * 10 + (str[i++] - '0');
			return (nbr * signo);
		}		
		i++;
	}
	return (nbr);
}

int main(void)
{
	char a[] = "---z123asd";
	printf("%d",ft_atoi(a));
}
