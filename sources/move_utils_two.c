/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:27:49 by atouba            #+#    #+#             */
/*   Updated: 2022/12/19 19:07:15 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		g_a;
int		g_b;
void	*g_black;
int		g_x;
int		g_y;
int		g_usls;

void	func_l(t_two *two, int g_x, int g_y)
{
	if (*two->data->col_count >= *two->data->col_num
		&& two->map->mp[g_y / 48][g_x / 48 - 1] == 'E')
	{
		ft_putnbr(*two->data->pl_moves);
		write(1, "\n", 1);
		*two->data->pl_moves = *two->data->pl_moves + 1;
		g_black = mlx_xpm_file_to_image(two->data->mlx, "images/croped.xpm",
				&g_a, &g_b);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y);
		empty_to_map(two->data, g_x, g_y);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x - 48, g_y);
		empty_to_map(two->data, g_x - 48, g_y);
		start_pos_to_map(two->data, g_x - 48, g_y, &g_usls);
		ft_putstr("Congratulations. You won");
		exit(0);
	}
}

void	func_l_t(t_two *two, int g_x, int g_y)
{
	if (two->map->mp[g_y / 48][g_x / 48 - 1] != '1' &&
		two->map->mp[g_y / 48][g_x / 48 - 1] != 'E')
	{
		ft_putnbr(*two->data->pl_moves);
		write(1, "\n", 1);
		*two->data->pl_moves = *two->data->pl_moves + 1;
		if (two->map->mp[g_y / 48][g_x / 48 - 1] == 'C')
			*two->data->col_count = *two->data->col_count + 1;
		g_black = mlx_xpm_file_to_image(two->data->mlx, "images/croped.xpm",
				&g_a, &g_b);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y);
		empty_to_map(two->data, g_x, g_y);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x - 48, g_y);
		empty_to_map(two->data, g_x - 48, g_y);
		start_pos_to_map(two->data, g_x - 48, g_y, &g_usls);
	}
}

void	func_d(t_two *two, int g_x, int g_y)
{
	if (*two->data->col_count >= *two->data->col_num
		&& two->map->mp[g_y / 48 + 1][g_x / 48] == 'E')
	{
		ft_putnbr(*two->data->pl_moves);
		write(1, "\n", 1);
		*two->data->pl_moves = *two->data->pl_moves + 1;
		g_black = mlx_xpm_file_to_image(two->data->mlx, "images/croped.xpm",
				&g_a, &g_b);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y);
		empty_to_map(two->data, g_x, g_y);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y + 48);
		empty_to_map(two->data, g_x, g_y + 48);
		start_pos_to_map(two->data, g_x, g_y + 48, &g_usls);
		ft_putstr("Congratulations. You won");
		exit(0);
	}
}

void	func_d_t(t_two *two, int g_x, int g_y)
{
	if (two->map->mp[g_y / 48 + 1][g_x / 48] != '1' &&
		two->map->mp[g_y / 48 + 1][g_x / 48] != 'E')
	{
		if (two->map->mp[g_y / 48 + 1][g_x / 48] == 'C')
			*two->data->col_count = *two->data->col_count + 1;
		ft_putnbr(*two->data->pl_moves);
		write(1, "\n", 1);
		*two->data->pl_moves = *two->data->pl_moves + 1;
		g_black = mlx_xpm_file_to_image(two->data->mlx, "images/croped.xpm",
				&g_a, &g_b);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y);
		empty_to_map(two->data, g_x, g_y);
		mlx_put_image_to_window(two->data->mlx, two->data->win, g_black,
			g_x, g_y + 48);
		empty_to_map(two->data, g_x, g_y + 48);
		start_pos_to_map(two->data, g_x, g_y + 48, &g_usls);
	}
}
