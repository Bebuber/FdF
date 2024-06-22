/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:25:37 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/22 19:31:10 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *param)
{
	if (key == 126)
		param->shift_y -= 100;
	if (key == 125)
		param->shift_y += 100;
	if (key == 123)
		param->shift_x -= 100;
	if (key == 124)
		param->shift_x += 100;
	if (key == 69)
		param->zoom += 4;
	if (key == 78 && param->zoom > 1)
		param->zoom -= param->zoom / 2;
	if (key == 86)
		param->angle -= 0.15;
	if (key == 88)
		param->angle += 0.15;
	if (key == 87)
		param->is_iso *= -1;
	if (key == 53)
		free_exit_succesfully(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_map(param);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_fdf *param)
{
	if (button == 1)
	{
		param->shift_x = x;
		param->shift_y = y;
	}
	if (button == 2)
	{
		param->angle = 0.8;
		param->zoom = 7;
		param->shift_x = param->win_x / 2.5;
		param->shift_y = param->win_y / 15;
	}
	if (button == 3)
		param->is_iso *= -1;
	if (button == 4)
		param->zoom += 4;
	if (button == 5 && param->zoom > 1)
		param->zoom -= param->zoom / 2;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_map(param);
	return (0);
}
