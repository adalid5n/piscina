/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:03:00 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/25 18:05:18 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	cont;

	cont = 0;
	while (*str != '\0')
	{
		cont++;
		str++;
	}
	return (cont);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > 0 && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			c = ft_strncmp(&str[i], to_find, ft_strlen(to_find));
			if (c == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
	char a[] = "abcdpuafghi";
	char b[] = "pua";
	printf("%s",ft_strstr(a, b));

}*/
