/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:09:25 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/23 11:57:15 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *game)
{
	mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	mlx_destroy_image(game->mlx.ptr, game->img.path);
	ft_freemap(game);
	exit(0);
}

void	pos_p(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->hook.y = y;
				game->hook.x = x;
			}
			if (game->map[y][x] == 'C')
				game->hook.c++;
			if (game->map[y][x] == 'E')
			{
				game->hook.ye = y;
				game->hook.xe = x;
			}
		}
	}
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 53)
		ft_exit(game);
	if (keycode == 2 && game->map[game->hook.y][game->hook.x + 1] != '1')
		right(game);
	if (keycode == 0 && game->map[game->hook.y][game->hook.x - 1] != '1')
		left(game);
	if (keycode == 1 && game->map[game->hook.y + 1][game->hook.x] != '1')
		down(game);
	if (keycode == 13 && game->map[game->hook.y - 1][game->hook.x] != '1')
		up(game);
	return (0);
}
