/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:04 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/19 21:40:59 by bebuber          ###   ########.fr       */
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

typedef struct s_point
{
	int	z;
	int	color;
}	t_point;

typedef struct fdf
{
	t_point		**map;
	int			height;
	int			width;
	int			shift_x;
	int			shift_y;
	int			win_x;
	int			win_y;
	int			zoom;

	void		*mlx_ptr;
	void		*win_ptr;

}	t_fdf;

int		main(int argc, char **argv);

// read_file.c		&&		read_file_utils.c
t_point	**read_file(char *file, t_fdf *data);
void	is_valid(char **tmp, char **nums, t_point **map, t_fdf *data);
int		hex_to_int(char *str);
void	*ft_malloc(size_t size);
// error.c
void	print_error_exit(int code);
void	free_arrays_and_exit(char **tmp, char **nums, t_point **map, t_fdf *data);
void	free_data(t_fdf *data, t_point **map);
void	free_exit_succesfully(t_fdf *data, t_point **map);
// draw.c
void	draw_map(t_fdf *data);
int		check_file(char *file);
#endif