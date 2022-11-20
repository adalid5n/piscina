/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:21:33 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/25 18:04:19 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

/*int main (void)
{
	char a[] = "hahiha";
	char b[] = "hahahe";
	int c;
	int d;
	
	c = ft_strncmp(a, b, 3);
	d = strncmp(a, b, 3);
	printf("%d", c);	
	printf("%d", d);	
}*/
