/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:02:48 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/27 16:01:35 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	up;

	i = 0;
	up = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			if (up == 1)
			{
				str[i] -= 32;
				up = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			up = 0;
		else
			up = 1;
		i++;
	}
	return (str);
}

/*int main (void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s",ft_strcapitalize(a));
}*/
