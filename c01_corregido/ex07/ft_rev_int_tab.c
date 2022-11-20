/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:38:01 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/22 16:38:29 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int	cont;

	cont = 0;
	while (cont < size / 2)
	{
		aux = tab[cont];
		tab[cont] = tab[size - 1 - cont];
		tab[size - 1 - cont] = aux;
		cont++;
	}
}
