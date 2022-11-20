/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:21:33 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/30 22:06:09 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && (i < n -1))
			i++;
	return (s1[i] - s2[i]);
}

int main (void)
{
	char a[] = "hahaha";
	char b[] = "hahdhe";
	int c;
	int d;
	
	c = ft_strncmp(a, b, 4);
	d = strncmp(a, b, 4);
	printf("%d", c);	
	printf("%d", d);	
}
