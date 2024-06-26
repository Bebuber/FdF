/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:07:02 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/24 16:16:31 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_defaults(t_fdf *data)
{
	data->angle = 0.8;
	data->zoom = 2;
	data->z_zoom = 0;
	data->win_x = 1300;
	data->win_y = 800;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->is_iso = -1;
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
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.data = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_mouse_hook(data->win_ptr, deal_mouse, data);
	mlx_hook(data->win_ptr, 17, 0, free_exit_succesfully, data);
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