/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:55:43 by bebuber           #+#    #+#             */
/*   Updated: 2024/06/16 17:27:59 by bebuber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int argc, char *str)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf [file]\n");
		exit(1);
	}
	if (open(str, O_RDONLY) == -1)
	{
		ft_printf("File not found\n");
		exit(1);
	}
}
