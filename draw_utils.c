/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/22 21:35:07 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_point *p1, t_point *p2, t_fdf *data)
{
	if (data->zoom < 0)
		data->zoom = 1;
	(*p1).x *= data->zoom;
	(*p1).y *= data->zoom;
	(*p2).x *= data->zoom;
	(*p2).y *= data->zoom;
}

void	iso(t_point *p1, t_point *p2, float angle)
{
	float	x;
	float	y;
	float	z;

	x = (*p1).x;
	y = (*p1).y;
	z = (*p1).z;
	(*p1).x = (x - y) * cos(angle);
	(*p1).y = (x + y) * sin(angle) - z;
	x = (*p2).x;
	y = (*p2).y;
	z = (*p2).z;
	(*p2).x = (x - y) * cos(angle);
	(*p2).y = (x + y) * sin(angle) - z;
}

void	set_values(t_point *p1, t_point *p2, t_fdf *data)
{
	zoom(p1, p2, data);
	if (data->is_iso == 1)
		iso(p1, p2, data->angle);
	(*p1).x += data->shift_x;
	(*p1).y += data->shift_y;
	(*p2).x += data->shift_x;
	(*p2).y += data->shift_y;
}

void	push_img(t_fdf *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	data->img.data = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
}

