/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/21 15:30:56 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	wdcounter(char *line, int width, int hght)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			while ((line[i] >= '0' && line[i] <= '9') || line[i] == '-'\
			|| line[i] == ',' || line[i] == 'x' || (line[i] >= 'a' && \
			line[i] <= 'f') || (line[i] >= 'A' && line[i] <= 'F'))
				i++;
			count++;
		}
		else if (line[i] != ' ')
			i++;
	}
	// hght = 0;
	// width = count;
	if (hght != 0 && count != width)
		print_error_exit(3);
	return (count);
}

t_point	**get_height(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		hght;
	int		width;
	t_point	**map;

	hght = 0;
	width = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		width = wdcounter(line, width, hght);
		hght++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	map = (t_point **)ft_malloc(sizeof(t_point *) * (hght + 1));
	data->height = hght;
	while (--hght >= 0)
		map[hght] = (t_point *)ft_malloc(sizeof(t_point) * (width + 1));
	data->width = width;
	return (map);
}

int	get_color(char *str)
{
	int		i;
	int		n;
	int		res;

	i = 0;
	n = 0;
	res = 0;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10;
		res = res * 16 + n;
		i++;
	}
	return (res);
}

void	create_map(char *line, t_point **map, int y, t_fdf *data)
{
	char	**nums;
	char	**tmp;
	int		x;
	int		i;

	nums = ft_split(line, ' ');
	x = 0;
	i = 0;
	while (nums[x])
	{
		tmp = ft_split(nums[x], ',');
		is_valid(tmp, nums, map, data);
		map[y][x].z = ft_atoi(tmp[0]);
		map[y][x].x = x;
		map[y][x].y = y;
		if (tmp[1])
			map[y][x].color = get_color(tmp[1]);
		else
			map[y][x].color = -1;
		free_arr(tmp);
		x++;
	}
	free_arr(nums);
}

t_point	**read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;
	t_point	**map;

	i = 0;
	map = get_height(file, data);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (i < data->height)
	{
		create_map(line, map, i, data);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	if (line)
		free (line);
	close(fd);

	return (map);
}
