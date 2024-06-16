/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:04 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/16 17:00:17 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
//# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct fdf
{
	int		height;
	int		width;
	int		**map;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;

}	fdf_t;

typedef struct mlx
{
	void*	window;
	void*	context;
	int32_t	width;
	int32_t	height;
	double	delta_time;
}	mlx_t;

int		main(int argc, char **argv);

void	read_file(char *file, fdf_t *data);
void	draw(float x, float y, float x1, float y1, fdf_t *data);
void	draw_map(fdf_t *data);
void	error(int argc, char *str);

#endif