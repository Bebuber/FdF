/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:25:37 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/20 19:35:51 by bebuber          ###   ########.fr       */
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
		free_exit_succesfully(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_map(param);
	return (0);
}
