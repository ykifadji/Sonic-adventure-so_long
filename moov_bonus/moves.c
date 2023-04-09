/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:50:42 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/28 08:12:28 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	path_moves(t_data *game)
{
	game->img.nine = "./sprites/9.xpm";
	game->img.nine = mlx_xpm_file_to_image(game->mlx.ptr, game->img.nine, \
		&game->img.width, &game->img.height);
	game->img.eight = "./sprites/8.xpm";
	game->img.eight = mlx_xpm_file_to_image(game->mlx.ptr, game->img.eight, \
		&game->img.width, &game->img.height);
	game->img.seven = "./sprites/7.xpm";
	game->img.seven = mlx_xpm_file_to_image(game->mlx.ptr, game->img.seven, \
		&game->img.width, &game->img.height);
	game->img.six = "./sprites/6.xpm";
	game->img.six = mlx_xpm_file_to_image(game->mlx.ptr, game->img.six, \
		&game->img.width, &game->img.height);
	game->img.five = "./sprites/5.xpm";
	game->img.five = mlx_xpm_file_to_image(game->mlx.ptr, game->img.five, \
		&game->img.width, &game->img.height);
}

void	path_movess(t_data *game)
{
	game->img.four = "./sprites/4.xpm";
	game->img.four = mlx_xpm_file_to_image(game->mlx.ptr, game->img.four, \
		&game->img.width, &game->img.height);
	game->img.three = "./sprites/3.xpm";
	game->img.three = mlx_xpm_file_to_image(game->mlx.ptr, game->img.three, \
		&game->img.width, &game->img.height);
	game->img.two = "./sprites/2.xpm";
	game->img.two = mlx_xpm_file_to_image(game->mlx.ptr, game->img.two, \
		&game->img.width, &game->img.height);
	game->img.one = "./sprites/1.xpm";
	game->img.one = mlx_xpm_file_to_image(game->mlx.ptr, game->img.one, \
		&game->img.width, &game->img.height);
	game->img.zero = "./sprites/0.xpm";
	game->img.zero = mlx_xpm_file_to_image(game->mlx.ptr, game->img.zero, \
		&game->img.width, &game->img.height);
	path_moves(game);
}

void	reset_wall(t_data *game, int x)
{
	if (x == 1)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.wall, 5 * 64, 0 * 64);
	else if (x == 2)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.wall, 4 * 64, 0 * 64);
	else if (x == 3)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.wall, 3 * 64, 0 * 64);
}

static void	set_movess(t_data *game)
{
	if (game->hook.i % 10 == 5)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.five, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 6)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.six, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 7)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.seven, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 8)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.eight, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 9)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.nine, 5 * 64, 0 * 64);
	moves_three(game);
}

void	set_moves(t_data *game)
{
	reset_wall(game, 1);
	if (game->hook.i % 10 == 0)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.zero, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 1)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.one, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 2)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.two, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 3)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.three, 5 * 64, 0 * 64);
	else if (game->hook.i % 10 == 4)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.four, 5 * 64, 0 * 64);
	set_movess(game);
}
