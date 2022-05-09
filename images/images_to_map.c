/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:49:07 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:21:06 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	wall_to_map(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x, y);
}

void	collectible_to_map(t_data *data, int x, int y, int *c)
{
	*c = *c + 1;
	mlx_put_image_to_window(data->mlx, data->win, data->img_col, x, y);
}

void	exit_to_map(t_data *data, int x, int y, int *ex)
{
	*ex = 1;
	mlx_put_image_to_window(data->mlx, data->win, data->img_exit, x, y);
}

void	empty_to_map(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img_empty, x, y);
}

void	start_pos_to_map(t_data *data, int x, int y, int *pl_n)
{
	*pl_n = 1;
	*data->player_x = x;
	*data->player_y = y;
	mlx_put_image_to_window(data->mlx, data->win, data->img_start_pos, x, y);
}
