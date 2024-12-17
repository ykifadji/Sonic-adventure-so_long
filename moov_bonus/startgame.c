/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:00:50 by ykifadji          #+#    #+#             */
/*   Updated: 2024/12/17 08:32:42 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	startgame(t_data *game, int keycode)
{
	if ((keycode == 36 || keycode == 76 || keycode == 65293) && game->hook.k <= 1)
	{
		game->img.path = "./sprites/startgame.xpm";
		game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
			&game->img.width, &game->img.height);
		if (!game->img.path)
			ft_handlerror(9);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, 0 * 64, 0 * 64);
		if (game->hook.k == 1)
		{
			background(game);
			ft_moves(game);
		}
		game->hook.k++;
	}
}

void	endgame(t_data *game, int keycode)
{
	if ((keycode == 36 || keycode == 76 || keycode == 65293) && game->hook.k <= 1)
	{
		game->start = 0;
		game->img.path = "./sprites/endgame.xpm";
		game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
			&game->img.width, &game->img.height);
		if (!game->img.path)
			ft_handlerror(9);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, 0 * 64, 0 * 64);
		if (game->hook.k == 1)
		{
			background(game);
			ft_moves(game);
			game->start = 1;
		}
		game->hook.k++;
	}
}

void	game_init(t_data *game, int c)
{
	parsing(game, game->argv1);
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		return ;
	game->mlx.size_x = game->len * 64;
	game->mlx.size_y = game->line * 64;
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->mlx.size_x, \
		game->mlx.size_y, "Sonic");
	game->hook.c = 0;
	pos_p(game);
	game->hook.a = 3;
	game->mlx.frame = 0;
	path_col(game);
	path_enemy(game);
	path_movess(game);
	game->hook.i = 1;
	game->hook.k = 0;
	if (c == 0)
		startgame(game, 36);
	if (c == 1)
		endgame(game, 36);
	mlx_key_hook(game->mlx.win, key_hook, game);
	mlx_hook(game->mlx.win, 17, 0, ft_exit, game);
	mlx_loop(game->mlx.ptr);
}
