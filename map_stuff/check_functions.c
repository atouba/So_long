/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funtions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 06:16:34 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 06:17:17 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int	is_rec(char **map)
{
	int	i;
	int	j;
	int	l;

	i = 1;
	l = lenght_line(map[0]);
	while (map[i] && lenght_line(map[i]))
	{
		j = 0;
		while (j < i)
		{
			if (lenght_line(map[j]) != lenght_line(map[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	g_i;
int	g_j;

int	is_surrounded_one(char **map, int w, int h)
{
	g_i = 0;
	g_j = 0;
	while (g_j < w)
	{
		if (map[0][g_j] != '1' && map[0][g_j] != '\n')
			return (0);
		g_j++;
	}
	g_j--;
	while (g_i < h)
	{
		if (map[g_i][g_j] != '1')
			return (0);
		g_i++;
	}
	return (1);
}

int	is_surrounded_two(char **map, int w, int h)
{
	if (!is_surrounded_one(map, w, h))
		return (0);
	g_j = w - 1;
	g_i = h - 1;
	while (g_j >= 0)
	{
		if (map[g_i][g_j] != '1')
			return (0);
		g_j--;
	}
	g_j = 0;
	while (g_i >= 0)
	{
		if (map[g_i][g_j] != '1')
			return (0);
		g_i--;
	}
	return (1);
}

int	is_chars_in(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
