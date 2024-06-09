/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:07:02 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/09 15:08:04 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# include <stdio.h>

//read input file 
//get height 
//get width
//create a **int with malloc using the heiht and width 
//use split and atoi to write values into **map;

int	main(int argc, char **argv)
{
	fdf	*data;

	data = (fdf*)malloc(sizeof(fdf));

	read_file(argv[1], data);
	int	i;
	int	j;
	i = 0;
	j = 0;
	argc = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%2d ", data->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
