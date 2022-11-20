/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:01 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/27 17:23:44 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void putarr(char src[])
{
    int i;
    i = 0;
    while (src[i] != '\0')
    {
        ft_putchar(src[i]);
        i++;
    }
}

int		check_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	return (1);
}

void	convert_hexa(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i])
	{
		if (check_printable(str[i]))
            ft_putchar(str[i]);
		else
			convert_hexa(str[i]);
		i++;
	}
}
