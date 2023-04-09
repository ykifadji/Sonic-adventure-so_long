/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 08:08:15 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/28 07:02:46 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	path_col(t_data *game)
{
	game->img.col1 = "./sprites/col1.xpm";
	game->img.col1 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.col1, \
		&game->img.width, &game->img.height);
	game->img.col2 = "./sprites/col2.xpm";
	game->img.col2 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.col2, \
		&game->img.width, &game->img.height);
	game->img.col3 = "./sprites/col3.xpm";
	game->img.col3 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.col3, \
		&game->img.width, &game->img.height);
	game->img.col4 = "./sprites/col4.xpm";
	game->img.col4 = mlx_xpm_file_to_image(game->mlx.ptr, game->img.col4, \
		&game->img.width, &game->img.height);
	if (!game->img.col1 || !game->img.col2 || !game->img.col3 \
		|| !game->img.col4)
		ft_handlerror(9);
}

static void	mvt_coll(t_data *game)
{
	if (game->mlx.frame % 6000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.col3, game->pos.x * 64, game->pos.y * 64);
	}
	else if (game->mlx.frame % 4000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.col4, game->pos.x * 64, game->pos.y * 64);
	}
}

static void	mvt_col(t_data *game)
{
	if (game->mlx.frame % 10000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.col1, game->pos.x * 64, game->pos.y * 64);
	}
	else if (game->mlx.frame % 8000 == 0)
	{
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.grass, game->pos.x * 64, game->pos.y * 64);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.col2, game->pos.x * 64, game->pos.y * 64);
	}
	mvt_coll(game);
}

static void	mv_col(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
			{
				game->pos.y = y;
				game->pos.x = x;
				mvt_col(game);
			}
		}
	}
}

int	update(t_data *game)
{
	if (game->start != 0)
	{
		game->mlx.frame++;
		if (game->mlx.frame > 2147483646)
			game->mlx.frame = 0;
		if (game->map[game->hook.y][game->hook.x] != 'A')
		{
			mv_col(game);
			enemy(game);
		}
	}
	return (0);
}
