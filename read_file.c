/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/15 15:47:32 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	wdcounter(char *line, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == c)
			i++;
		if (line[i] >= '0' && line[i] <= '9')
		{
			while (line[i] >= '0' && line[i] <= '9')
				i++;
			count++;
		}
		else if (line[i] != c)
			i++;
	}
	return (count);
}

void	get_height(char *file, fdf_t *data)
{
	char	*line;
	int		fd;
	int		hght;
	int		width;

	fd = open(file, O_RDONLY);
	hght = 0;
	width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		hght++;
		if (wdcounter(line, ' ') > width)
			width = wdcounter(line, ' ');
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	data->width = width;
	data->height = hght;
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

void	read_file(char *file, fdf_t *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	get_height(file, data);
	data->map = (int **)malloc(sizeof(int *) * (data->height + 1));
	while (i <= data->height)
		data->map[i++] = (int *)malloc(sizeof(int) * (data->width));
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (i < data->height)
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
