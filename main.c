/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:07:02 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/19 21:40:16 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *param)
{
	ft_printf("key: %d\n", key);
	if (key == 126)
		param->shift_y -= 10;
	if (key == 125)
		param->shift_y += 10;
	if (key == 123)
		param->shift_x -= 10;
	if (key == 124)
		param->shift_x += 10;
	if (key == 53)
		free_exit_succesfully(param, param->map);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_map(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	t_point	**map;

	if (argc != 2)
		print_error_exit(2);
	else if (check_file(argv[1]) == -1)
		print_error_exit(1);
	data = (t_fdf *)ft_malloc(sizeof(t_fdf));
	map = read_file(argv[1], data);
	data->map = map;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1300, 800, "FDF");
	data->zoom = 20;
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free_exit_succesfully(data, map);
}
	//int	i;
	//int	j;
	//i = 0;
	//j = 0;
	//while (i < data->height)
	//{
	//	j = 0;
	//	while (j < data->width)
	//	{
	//		printf("%2d ", data->map[i][j]);
	//		j++;
	//	}
	//	printf("\n");
	//	i++;
	//}