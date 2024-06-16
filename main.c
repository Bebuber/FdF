/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:07:02 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/16 17:39:37 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, fdf_t *param)
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
		exit(0);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_map(param);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf_t	*data;

	error(argc, argv[1]);
	data = (fdf_t *)malloc(sizeof(fdf_t));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
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