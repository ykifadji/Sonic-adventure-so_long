/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:15:53 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/25 17:32:12 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reset_floor(t_data *game, int m)
{
	game->hook.a--;
	ft_floor(game, m);
	game->img.path = "./sprites/sonic_red.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.path, game->hook.x * 64, game->hook.y * 64);
}

void	path_enemy(t_data *game)
{
	game->img.enemy1 = "./sprites/enemy1.xpm";
	game->img.enemy1 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.enemy1, \
		&game->img.width, &game->img.height);
	game->img.enemy2 = "./sprites/enemy2.xpm";
	game->img.enemy2 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.enemy2, \
		&game->img.width, &game->img.height);
	game->img.enemy3 = "./sprites/enemy3.xpm";
	game->img.enemy3 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.enemy3, \
		&game->img.width, &game->img.height);
	game->img.enemy4 = "./sprites/enemy4.xpm";
	game->img.enemy4 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.enemy4, \
		&game->img.width, &game->img.height);
	if (!game->img.enemy1 || !game->img.enemy2 || !game->img.enemy3 \
		|| !game->img.enemy4)
		ft_handlerror(9);
}

static void	mvt_enemy(t_data *game)
{
	if (game->mlx.frame % 6000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.enemy3, game->pos.x * 64, game->pos.y * 64);
	}
	else if (game->mlx.frame % 4000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.enemy4, game->pos.x * 64, game->pos.y * 64);
	}
}

void	mv_enemy(t_data *game)
{
	if (game->mlx.frame % 10000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.enemy1, game->pos.x * 64, game->pos.y * 64);
	}
	else if (game->mlx.frame % 8000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.enemy2, game->pos.x * 64, game->pos.y * 64);
	}
	mvt_enemy(game);
}

void	enemy(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'A')
			{
				game->pos.y = y;
				game->pos.x = x;
				mv_enemy(game);
			}
		}
	}
}
