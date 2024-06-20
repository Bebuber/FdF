/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:04:27 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/20 22:15:20 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)

void	iso(float *x, float *y, t_fdf *data)
{
	float	z;

	z = data->map[(int)*y][(int)*x].z;
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	zoom(float *x, float *y, t_fdf *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}


void	set_values(t_point p1, t_point p2, t_fdf *data)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = p1.x;
	y = p1.y;
	x1 = p2.x;
	y1 = p2.y;
	if (data->zoom != 1)
	{
		zoom(&x, &y, data);
		zoom(&x1, &y1, data);
	}
	if (data->angle != 0)
	{
		iso(&x, &y, data);
		iso(&x1, &y1, data);
	}
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	set_color(t_point p1, t_point p2)
{
	if (p1.color < 0 && p2.color < 0)
		return (p2.z > p1.z ? 0xff0000 : 0x00ff00);
	else if (p2.color > 0 && p1.color > 0)
		return (p2.z > p1.z ? p2.color : p1.color);
	else
		return (p2.color > 0 ? p2.color : p1.color);
}

void	set_x_y(t_point p, int x, int y)
{
	p.x = x;
	p.y = y;
}

void	draw_line(int x, int y, int x1, int y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		color;
	float	max;
	t_point	**map;

	map = data->map;
	set_x_y(map[y][x], x, y);
	set_x_y(map[y1][x1], x1, y1);
	color = set_color(data->map[y][x], data->map[y1][x1]);
	set_values(map[y][x], map[y][x], data);
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		x += x_step;
		y += y_step;
		if (x < 0 || x > data->win_x || y < 0 || y > data->win_y)
			break ;
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(x, y, x + 1, y, data);
			if (y < data->height - 1)
				draw_line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
