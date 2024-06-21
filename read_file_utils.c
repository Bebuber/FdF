/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:33 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/21 14:57:48 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_valid(char **tmp, char **nums, t_point **map, t_fdf *data)
{
	int	i;

	i = 0;
	if (!tmp)
		free_arrays_and_exit(tmp, nums, map, data);
	if (tmp[0][i] == '-')
		i++;
	while (tmp && tmp[0][i])
	{
		if ((tmp[0][i] < '0' || tmp[0][i] > '9') && (tmp[0][i] != '\n'))
			free_arrays_and_exit(tmp, nums, map, data);
		i++;
	}
	i = 0;
	while (tmp[1] && tmp[1][i])
	{
		if (tmp[1][i] == '0' && tmp[1][i + 1] == 'x')
			i += 2;
		if (!((tmp[1][i] >= '0' && tmp[1][i] <= '9') || (tmp[1][i] >= 'a'\
		&& tmp[1][i] <= 'f') || (tmp[1][i] >= 'A' && tmp[1][i] <= 'F') || tmp[1][i] == '\n'))
			free_arrays_and_exit(tmp, nums, map, data);
		i++;
	}
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_error_exit(4);
	return (ptr);
}
