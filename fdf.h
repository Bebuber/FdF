/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:04 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/24 15:43:59 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct fdf
{
	t_point		**map;
	t_img		img;
	int			height;
	int			width;
	int			shift_x;
	int			shift_y;
	int			win_x;
	int			win_y;
	int			zoom;
	float		angle;
	int			is_iso;

	void		*mlx_ptr;
	void		*win_ptr;

}	t_fdf;

// main.c
int		main(int argc, char **argv);

// read_file.c		&&		read_file_utils.c
t_point	**read_file(char *file, t_fdf *data);
void	is_valid(char **tmp, char **nums, t_point **map, t_fdf *data);
int		hex_to_int(char *str);
void	*ft_malloc(size_t size);
void	tmp_trim(char **tmp, t_point **map, int x, int y);
int		get_color(char *str);

// error.c
void	print_error_exit(int code);
void	free_arrays_and_exit(char **tmp, char **nums, \
t_point **map, t_fdf *data);
void	free_data_map_separately(t_fdf *data, t_point **map);
int		free_exit_succesfully(t_fdf *data);
void	free_arr(char **arr);

// draw.c
void	draw_map(t_fdf *data);
int		check_file(char *file);
void	draw_line(t_point p1, t_point p2, t_fdf *data);

// draw.utils.c
void	zoom(t_point *p1, t_point *p2, t_fdf *data);
void	iso(t_point *p1, t_point *p2, float angle);
void	set_values(t_point *p1, t_point *p2, t_fdf *data);
void	push_img(t_fdf *data);
void	color_pixel(t_fdf *data, int x, int y, int color);

// key_hook.c
int		deal_key(int key, t_fdf *param);
int		deal_mouse(int button, int x, int y, t_fdf *param);

#endif