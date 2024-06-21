/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:43:48 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/21 16:14:09 by bebuber          ###   ########.fr       */
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
