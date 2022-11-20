/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:23:38 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/23 15:24:39 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	result;

	result = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
			result = 0;
		i++;
	}
	return (result);
}
