/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:03:16 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:32:17 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int	echap(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	ft_close(void)
{
	exit(1);
	return (0);
}

void	play(t_two *two)
{
	mlx_key_hook(two->data->win, move, two);
	mlx_hook(two->data->win, 17, 1L << 0, ft_close, NULL);
}
