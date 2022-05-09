/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:38:49 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:31:31 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		g_a;
int		g_b;
void	*g_black;
int		g_x;
int		g_y;

void	mv_down(t_two *two)
{
	g_x = *two->data->player_x;
	g_y = *two->data->player_y;
	func_d(two, g_x, g_y);
	func_d_t(two, g_x, g_y);
}

void	mv_right(t_two *two)
{
	g_x = *two->data->player_x;
	g_y = *two->data->player_y;
	func_r(two, g_x, g_y);
	func_r_t(two, g_x, g_y);
}

void	mv_left(t_two *two)
{
	g_x = *two->data->player_x;
	g_y = *two->data->player_y;
	func_l(two, g_x, g_y);
	func_l_t(two, g_x, g_y);
}

void	mv_up(t_two *two)
{
	g_x = *two->data->player_x;
	g_y = *two->data->player_y;
	func_u(two, g_x, g_y);
	func_u_t(two, g_x, g_y);
}

int	move(int keycode, t_two *two)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124 || keycode == 2)
		mv_right(two);
	else if (keycode == 123 || keycode == 0)
		mv_left(two);
	else if (keycode == 126 || keycode == 13)
		mv_up(two);
	else if (keycode == 125 || keycode == 1)
		mv_down(two);
	return (0);
}
