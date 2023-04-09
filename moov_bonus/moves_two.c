/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 07:49:16 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/28 10:50:20 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	movess_two(t_data *game)
{
	if (game->hook.v % 10 == 5)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.five, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 6)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.six, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 7)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.seven, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 8)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.eight, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 9)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.nine, 4 * 64, 0 * 64);
}

static void	moves_two(t_data *game)
{
	reset_wall(game, 2);
	if (game->hook.v % 10 == 0)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.zero, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 1)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.one, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 2)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.two, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 3)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.three, 4 * 64, 0 * 64);
	else if (game->hook.v % 10 == 4)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.four, 4 * 64, 0 * 64);
	movess_two(game);
}

static void	movess_three(t_data *game)
{
	if (game->hook.i / 100 == 5)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.five, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 6)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.six, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 7)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.seven, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 8)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.eight, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 9)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.nine, 4 * 64, 0 * 64);
	game->hook.v = game->hook.i / 10;
	moves_two(game);
}

void	moves_three(t_data *game)
{
	reset_wall(game, 3);
	if (game->hook.i / 100 == 0)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.zero, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 1)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.one, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 2)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.two, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 3)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.three, 3 * 64, 0 * 64);
	else if (game->hook.i / 100 == 4)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.four, 3 * 64, 0 * 64);
	movess_three(game);
}
