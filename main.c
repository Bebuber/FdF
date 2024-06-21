/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:07:02 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/21 15:29:55 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_defaults(t_fdf *data)
{
	data->angle = 0.8;
	data->zoom = 7;
	data->win_x = 2000;
	data->win_y = 1000;
	data->shift_x = data->win_x / 2.5;
	data->shift_y = data->win_y / 15;
	data->mlx_ptr = mlx_init();
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		print_error_exit(2);
	else if (check_file(argv[1]) == -1)
		print_error_exit(1);
	data = (t_fdf *)ft_malloc(sizeof(t_fdf));
	data->map = read_file(argv[1], data);
	set_defaults(data);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
// 		int	i;
// 	int	j;
// 	i = 0;
// 	j = 0;
// 	while (i < data->height)
// 	{
// 		j = 0;
// 		while (j < data->width)
// 		{
// 			printf("%2d ", data->map[i][j].z);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}