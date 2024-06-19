/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:55:43 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/19 21:37:27 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error_exit(int code)
{
	if (code == 1)
		write(2, "File not found\n", 15);
	if (code == 2)
		write(2, "Usage: ./fdf <filename>\n", 24);
	if (code == 3)
		write(2, "Invalid map\n", 12);
	if (code == 4)
		write(2, "Malloc error\n", 13);
	exit(EXIT_FAILURE);
}

void	free_arrays_and_exit(char **tmp, char **nums, t_point **map, t_fdf *data)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
		free(tmp[i++]);
	free(tmp);
	i = 0;
	while (nums && nums[i])
		free(nums[i++]);
	free(nums);
	free_data(data, map);
	print_error_exit(3);
}

int		check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

void	free_data(t_fdf *data, t_point **map)
{
	int		i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(data);
}

void	free_exit_succesfully(t_fdf *data, t_point **map)
{
	int		i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	free(data);
	system("leaks fdf");
	exit(EXIT_SUCCESS);
}
