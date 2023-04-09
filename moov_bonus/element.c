/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:14:09 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/27 13:05:31 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_moves(t_data *game)
{
	game->img.path = "./sprites/moves.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, \
	game->img.path, &game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.path, 0 * 64, 0 * 64);
}

static void	path_sonic_element(t_data *game)
{
	if (game->hook.a == 3)
		game->img.sonic_element = "./sprites/sonic_element3.xpm";
	if (game->hook.a == 2)
		game->img.sonic_element = "./sprites/sonic_element2.xpm";
	if (game->hook.a == 1)
		game->img.sonic_element = "./sprites/sonic_element1.xpm";
}

static void	path_elements(t_data *game)
{
	if (game->hook.c > 9)
		game->img.element = "./sprites/col_element+9.xpm";
	else if (game->hook.c == 9)
		game->img.element = "./sprites/col_element9.xpm";
	else if (game->hook.c == 8)
		game->img.element = "./sprites/col_element8.xpm";
	else if (game->hook.c == 7)
		game->img.element = "./sprites/col_element7.xpm";
	else if (game->hook.c == 6)
		game->img.element = "./sprites/col_element6.xpm";
	else if (game->hook.c == 5)
		game->img.element = "./sprites/col_element5.xpm";
	else if (game->hook.c == 4)
		game->img.element = "./sprites/col_element4.xpm";
	else if (game->hook.c == 3)
		game->img.element = "./sprites/col_element3.xpm";
	else if (game->hook.c == 2)
		game->img.element = "./sprites/col_element2.xpm";
	else if (game->hook.c == 1)
		game->img.element = "./sprites/col_element1.xpm";
	else if (game->hook.c == 0)
		game->img.element = "./sprites/col_completed.xpm";
}

void	set_element(t_data *game)
{
	if (game->hook.a <= 0)
		game_init(game, 1);
	path_sonic_element(game);
	game->img.sonic_element = mlx_xpm_file_to_image(game->mlx.ptr, \
		game->img.sonic_element, &game->img.width, &game->img.height);
	if (!game->img.sonic_element)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.sonic_element, (game->len - 3) * 64, 0 * 64);
	path_elements(game);
	game->img.element = mlx_xpm_file_to_image(game->mlx.ptr, game->img.element, \
		&game->img.width, &game->img.height);
	if (!game->img.element)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.element, (game->len - 3) * 64, 1 * 64);
}

void	set_enemy(t_data *game)
{
	int	y;
	int	x;

	game->img.path = "./sprites/enemy.xpm";
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
			if (game->map[y][x] == 'A')
				mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
					game->img.path, x * 64, y * 64);
		}
	}
	set_element(game);
}
