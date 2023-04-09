/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 07:16:41 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/28 07:24:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	tails(t_data *game)
{
	int	y;
	int	x;

	game->img.path = "./sprites/tails.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
					game->img.path, x * 64, y * 64);
		}
	}
	set_enemy(game);
}

static void	perso(t_data *game)
{
	int	y;
	int	x;

	game->img.path = "./sprites/sonic.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
					game->img.path, x * 64, y * 64);
				game->map[y][x] = '0';
			}
		}
	}
	tails(game);
}

static void	coll(t_data *game)
{
	int	y;
	int	x;

	game->img.path = "./sprites/collectible.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
					game->img.path, x + (x * 64), y + (y * 64));
		}
	}
	perso(game);
}

static void	wall(t_data *game)
{
	int	y;
	int	x;

	game->img.wall = "./sprites/wall.xpm";
	game->img.wall = mlx_xpm_file_to_image(game->mlx.ptr, game->img.wall, \
		&game->img.width, &game->img.height);
	if (!game->img.wall)
		ft_handlerror(9);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
					game->img.wall, x * 64, y * 64);
		}
	}
	coll(game);
}

void	background(t_data *game)
{
	int	y;
	int	x;

	game->img.path = "./sprites/grass.xpm";
	game->img.grass = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.grass)
		ft_handlerror(9);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
				game->img.grass, x * 64, y * 64);
	}
	wall(game);
}
