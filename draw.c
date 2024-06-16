/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:04:27 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/16 16:44:24 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void	iso(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.75);
	*y = (*x + *y) * sin(0.75) - z;
}

void	draw(float x, float y, float x1, float y1, fdf_t *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	data->color = (z || z1) ? 0xff0000 : 0xffffff;
	iso(&x, &y, z);
	iso(&x1, &y1, z1);
	
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_map(fdf_t *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw(x, y, x + 1, y, data);
			if (y < data->height - 1)
				draw(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}