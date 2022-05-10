/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:06:07 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 16:36:37 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

void	allocate(char ***mp, int **x, int **y, int **pl)
{
	*mp = malloc(sizeof(char *) * 40);
	*x = malloc(sizeof(int));
	*y = malloc(sizeof(int));
	*pl = malloc(sizeof(int));
	**pl = 1;
}

void	allocate_t(int **cc, int **cn, int **pl, int **exit)
{
	*cc = malloc(sizeof(int));
	*cn = malloc(sizeof(int));
	*pl = malloc(sizeof(int));
	*exit = malloc(sizeof(int));
	**cc = 0;
	**cn = 0;
	**pl = 0;
	**exit = 0;
}

t_map	g_map;
t_data	g_data;
t_two	g_two;
int		g_fd;
char	**g_mp;

void	check_file(int fd)
{
	if (g_fd < 0)
	{
		ft_putstr("Error: invalid map file\n");
		exit(1);
	}
}

void	ch_map(char **g_mp, int w, int h)
{
	if (!is_map_valid(g_mp, w, h))
	{
		ft_putstr("Error: invalid map\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	allocate(&g_mp, &g_data.player_x, &g_data.player_y, &g_data.pl_moves);
	allocate_t(&g_data.col_count, &g_data.col_num,
		&g_data.pl_n, &g_data.exit_n);
	g_fd = open(argv[1], O_RDONLY);
	check_file(g_fd);
	g_map = map_to_array(g_fd, g_mp);
	ch_map(g_mp, g_map.width, g_map.height);
	g_map.mp = g_mp;
	g_data.mlx = mlx_init();
	g_data.win = mlx_new_window(g_data.mlx, g_map.width * 48,
			g_map.height * 48, "so_long");
	init_images(&g_data);
	array_to_map(g_map, &g_data, g_data.col_num);
	if (!*g_data.col_num || !*g_data.exit_n || !*g_data.pl_n)
	{
		ft_putstr("Error: there must be at\
			least one collectible, exit and a player\n");
		exit (1);
	}
	g_two.map = &g_map;
	g_two.data = &g_data;
	play(&g_two);
	mlx_loop(g_data.mlx);
}
