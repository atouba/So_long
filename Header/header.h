/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:19:30 by atouba            #+#    #+#             */
/*   Updated: 2022/05/09 12:21:15 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_map
{
	int		width;
	int		height;
	char	**mp;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_col;
	void	*img_start_pos;
	void	*img_empty;
	void	*img_exit;
	int		*player_x;
	int		*player_y;
	int		*pl_moves;
	int		*col_count;
	int		*col_num;
	int		*pl_n;
	int		*exit_n;
}				t_data;

typedef struct s_two
{
	t_data	*data;
	t_map	*map;
}				t_two;

int		is_map_valid(char **map, int w, int h);
t_map	map_to_array(int fd, char **map);
int		lenght_line(char *line);
void	wall_to_map(t_data *data, int x, int y);
void	collectible_to_map(t_data *data, int x, int y, int *c);
void	exit_to_map(t_data *data, int x, int y, int *ex);
void	empty_to_map(t_data *data, int x, int y);
void	start_pos_to_map(t_data *data, int x, int y, int *pl_n);
void	array_to_map(t_map map, t_data *data, int *c);
void	init_images(t_data *data);
void	mv_left(t_two *two);
void	mv_right(t_two *two);
void	mv_up(t_two *two);
void	mv_down(t_two *two);
void	free_stuff(t_two *two, char **s);
int		move(int keycode, t_two *two);
void	play(t_two *two);
int		is_rec(char **map);
int		is_surrounded_one(char **map, int w, int h);
int		is_surrounded_two(char **map, int w, int h);
int		is_chars_in(char **map);
void	func_u(t_two *two, int g_x, int g_y);
void	func_u_t(t_two *two, int g_x, int g_y);
void	func_r(t_two *two, int g_x, int g_y);
void	func_r_t(t_two *two, int g_x, int g_y);
void	func_d(t_two *two, int g_x, int g_y);
void	func_d_t(t_two *two, int g_x, int g_y);
void	func_l(t_two *two, int g_x, int g_y);
void	func_l_t(t_two *two, int g_x, int g_y);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);

#endif