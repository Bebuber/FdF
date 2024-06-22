/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:04:27 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/22 22:15:10 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

float	find_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	set_color(t_point p1, t_point p2)
{
	if (p1.color < 0 && p2.color < 0)
	{
		if (p2.z > 0 || p1.z > 0)
			return (0x0000ff);
		else
			return (0xffa500);
	}
	else if (p2.color > 0 && p1.color > 0)
	{
		if (p2.z > p1.z)
			return (p2.color);
		else
			return (p1.color);
	}
	else if (p1.color > 0 && p2.color < 0)
		return (p1.color);
	else
		return (p2.color);
}

void	draw_line(t_point p1, t_point p2, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		color;
	float	max;
	char	*str;

	color = set_color(p1, p2);
	set_values(&p1, &p2, data);
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = find_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if (p1.x < 0 || p1.x > data->win_x || p1.y < 0 || p1.y > data->win_y)
			break ;
		printf("Here\n");
		str = data->img.data + (int)p1.x * 4 + (int)p1.y * data->img.size_line;
		*(unsigned int *)str = color;
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	draw_map(t_fdf *data)
{
	int		x;
	int		y;
	t_point	**map;

	map = data->map;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_line(map[y][x], map[y][x +1], data);
			if (y < data->height - 1)
				draw_line(map[y][x], map[y +1][x], data);
			x++;
		}
		y++;
	}
	push_img(data);
}
