/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:19:07 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 06:17:26 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int	lenght_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

int	is_map_valid(char **map, int w, int h)
{
	if (is_rec(map) && is_chars_in(map) && is_surrounded_two(map, w, h))
		return (1);
	return (0);
}
