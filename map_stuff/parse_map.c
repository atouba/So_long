/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 02:20:47 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:22:01 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

t_map	map_to_array(int fd, char **map)
{
	t_map	mp;
	int		i;

	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	mp.height = i;
	mp.width = lenght_line(map[0]);
	return (mp);
}

void	array_to_map(t_map map, t_data *data, int *c)
{
	int	i;
	int	j;

	i = 0;
	*c = 0;
	while (i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (map.mp[i][j] == '1')
				wall_to_map(data, j * 48, i * 48);
			else if (map.mp[i][j] == 'C')
				collectible_to_map(data, j * 48, i * 48, c);
			else if (map.mp[i][j] == '0')
				empty_to_map(data, j * 48, i * 48);
			else if (map.mp[i][j] == 'P')
				start_pos_to_map(data, j * 48, i * 48, data->pl_n);
			else if (map.mp[i][j] == 'E')
				exit_to_map(data, j * 48, i * 48, data->exit_n);
		}
		i++;
	}
}
