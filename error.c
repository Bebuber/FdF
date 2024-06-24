/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:55:43 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/24 16:19:50 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error_exit(int code)
{
	if (code == 1)
		write(2, "\033[0;31mFile not found\n\033[0m", 26);
	if (code == 2)
		write(2, "\033[0;31mUsage: ./fdf <filename>\n\033[0m", 35);
	if (code == 3)
		write(2, "\033[0;31mInvalid map\n\033[0m", 23);
	if (code == 4)
		write(2, "\033[0;31mMalloc error\n\033[0m", 24);
	if (code == 5)
		write(2, "\033[0;31mFile extension is not .fdf\n\033[0m", 38);
	exit(EXIT_FAILURE);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	check_file(char *file)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	while (file[i])
	{
		if (file[i] == '.')
			if (file[i + 1] == 'f' && file[i + 2] == 'd' && file[i + 3] == 'f')
				return (0);
		i++;
	}
	print_error_exit(5);
	return (-1);
}

void	free_data_map_separately(t_fdf *data, t_point **map)
{
	int		i;

	i = 0;
	if (map && map[0])
	{
		while (i < data->height)
			free(map[i++]);
		free(map);
	}
	if (data)
		free(data);
}

int	free_exit_succesfully(t_fdf *data)
{
	int		i;

	i = 0;
	if (data->map && data->map[0])
	{
		while (i < data->height)
			free(data->map[i++]);
		free(data->map);
	}
	if (data)
		free(data);
	write(1, "\033[0;32mExiting successfully!\n\033[0m", 33);
	exit(EXIT_SUCCESS);
	return (0);
}
// system("leaks fdf");
