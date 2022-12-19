/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:39:05 by atouba            #+#    #+#             */
/*   Updated: 2022/12/19 19:01:38 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	init_images(t_data *data)
{
	int	a;
	int	b;

	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"images/grass.xpm", &a, &b);
	data->img_col = mlx_xpm_file_to_image(data->mlx,
			"images/col.xpm", &a, &b);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"images/piano.xpm", &a, &b);
	data->img_empty = mlx_xpm_file_to_image(data->mlx,
			"images/zero.xpm", &a, &b);
	data->img_start_pos = mlx_xpm_file_to_image(data->mlx,
			"images/ast.xpm", &a, &b);
	if (!data->img_col || !data->img_wall || !data->img_start_pos
		|| !data->img_empty || !data->img_exit)
		exit (1);
}
