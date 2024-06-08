/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/08 17:34:16 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	wdcounter(char *line, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			i++;
		else if (line[i] >= 48 && line[i] <= 57)
		{
			while (line[i] >= 48 && line[i] <= 57)
				i++;
			count++;
		}
	}
	return (count);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	width = wdcounter(line, ' ');
	close (fd);
	free (line);
	return (width);
}

void	create_map(int *m_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		m_line[i] = ft_atoi(nums[i]);
		free (nums[i]);
		i++;
	}
	free (nums);
}

void	read_file(char *file, fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(file);
	data->width = get_width(file);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
		data->map[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		create_map(data->map[i], line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	close(fd);
	data->map[i] = NULL;
}
