/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguzman- <aguzman-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:58:12 by aguzman-          #+#    #+#             */
/*   Updated: 2022/08/31 17:00:55 by aguzman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_next_file(char *input, int *i)
{
	int		j;
	int		ii;
	int		size;
	char	*file;

	ii = *i;
	size = 0;
	while (input[ii] == 32)
		++ii;
	while (input[ii] > 32 && input[ii] <= 126)
	{
		++ii;
		++size;
	}
	file = (char *)malloc(size * sizeof(char));
	if (!file)
		ft_error("malloc error\n");
	ii = *i;
	while (input[ii] == 32)
		++ii;
	j = 0;
	while (input[ii] > 32 && input[ii] <= 126)
		file[j++] = input[ii++];
	file[j] = '\0';
	*i = ii;
	return (file);
}

int	ft_count_files(char *input)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (input[i])
	{
		if (input[i] > 32 && input[i] <= 126)
			++cont;
		while (input[i] > 32 && input[i] <= 126)
			++i;
		while (input[i] == 32)
			++i;
	}
	return (cont);
}

char	**ft_clean_input(char *input, int file_num)
{
	int		i;
	int		aux;
	char	**files;

	files = (char **)malloc(file_num * sizeof(char *));
	if (!files)
		ft_error("malloc error\n");
	i = 0;
	aux = -1;
	while (++aux < file_num)
	{
		files[aux] = ft_next_file(input, &i);
	}
	return (files);
}

struct s_files	*ft_read_map_files(void)
{
	int		size;
	int		file_num;
	char	buf[1024];
	t_files	*files;

	write(1, "Write your map files ", 21);
	write(1, "(each one separated by only one space): \n\t", 43);
	size = read(0, buf, 1024);
	buf[size - 1] = '\0';
	write(1, "\n", 1);
	printf("INPUT DE FILES: %s\n", buf);
	file_num = ft_count_files(buf);
	files = (t_files *)malloc(sizeof(t_files));
	if (!files)
		ft_error("malloc error\n");
	files->num = file_num;
	files->names = ft_clean_input(buf, file_num);
	return (files);
}
