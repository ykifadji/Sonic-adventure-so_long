/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:06:30 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/26 06:57:52 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	right(t_data *game)
{
	game->hook.x += 1;
	if (game->map[game->hook.y][game->hook.x] == 'A')
	{
		reset_floor(game, 4);
		return ;
	}
	if (game->map[game->hook.y][game->hook.x] == 'C')
	{
		game->map[game->hook.y][game->hook.x] = '0';
		game->hook.c--;
	}
	if (game->map[game->hook.y][game->hook.x] == 'E' \
		&& game->hook.c <= 0)
	{
		ft_exit(game);
		ft_printf("%d\n", game->hook.i++);
	}
	if (game->map[game->hook.y][game->hook.x] != 'E')
		perso_moov(game, 0);
	else
		perso_moov(game, 4);
}

void	left(t_data *game)
{
	game->hook.x -= 1;
	if (game->map[game->hook.y][game->hook.x] == 'A')
	{
		reset_floor(game, 5);
		return ;
	}
	if (game->map[game->hook.y][game->hook.x] == 'C')
	{
		game->map[game->hook.y][game->hook.x] = '0';
		game->hook.c--;
	}
	if (game->map[game->hook.y][game->hook.x] == 'E' \
		&& game->hook.c <= 0)
	{
		ft_exit(game);
		ft_printf("%d\n", game->hook.i++);
	}
	if (game->map[game->hook.y][game->hook.x] != 'E')
		perso_moov(game, 1);
	else
		perso_moov(game, 5);
}

void	down(t_data *game)
{
	game->hook.y += 1;
	if (game->map[game->hook.y][game->hook.x] == 'A')
	{
		reset_floor(game, 6);
		return ;
	}
	if (game->map[game->hook.y][game->hook.x] == 'C')
	{
		game->map[game->hook.y][game->hook.x] = '0';
		game->hook.c--;
	}
	if (game->map[game->hook.y][game->hook.x] == 'E' \
		&& game->hook.c <= 0)
	{
		ft_exit(game);
		ft_printf("%d\n", game->hook.i++);
	}
	if (game->map[game->hook.y][game->hook.x] != 'E')
		perso_moov(game, 2);
	else
		perso_moov(game, 6);
}

void	up(t_data *game)
{
	game->hook.y -= 1;
	if (game->map[game->hook.y][game->hook.x] == 'A')
	{
		reset_floor(game, 7);
		return ;
	}
	if (game->map[game->hook.y][game->hook.x] == 'C')
	{
		game->map[game->hook.y][game->hook.x] = '0';
		game->hook.c--;
	}
	if (game->map[game->hook.y][game->hook.x] == 'E' \
		&& game->hook.c <= 0)
	{
		ft_exit(game);
		ft_printf("%d\n", game->hook.i++);
	}
	if (game->map[game->hook.y][game->hook.x] != 'E')
		perso_moov(game, 3);
	else
		perso_moov(game, 7);
}
