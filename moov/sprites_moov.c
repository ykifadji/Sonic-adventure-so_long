/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_moov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:25:00 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/23 12:47:25 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floor(t_data *game, int m)
{
	game->img.path = "./sprites/grass.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.path, game->hook.x * 64, game->hook.y * 64);
	if (m == 0 || m == 4)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, (game->hook.x - 1) * 64, game->hook.y * 64);
	else if (m == 1 || m == 5)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, (game->hook.x + 1) * 64, game->hook.y * 64);
	else if (m == 2 || m == 6)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, game->hook.x * 64, (game->hook.y - 1) * 64);
	else if (m == 3 || m == 7)
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, game->hook.x * 64, (game->hook.y + 1) * 64);
}

void	sprites_exit(t_data *game, int m)
{
	game->img.path = "./sprites/tails.xpm";
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
		&game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.path, game->hook.xe * 64, game->hook.ye * 64);
	if (m == 4)
	{
		game->img.path = "./sprites/grass.xpm";
		game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, game->img.path, \
			&game->img.width, &game->img.height);
		if (!game->img.path)
			ft_handlerror(9);
		mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
			game->img.path, game->hook.xe * 64, game->hook.ye * 64);
	}
}

static void	sprites_moov(t_data *game, int m)
{
	if (m == 0)
		game->img.path = "./sprites/sonicright.xpm";
	if (m == 1)
		game->img.path = "./sprites/sonicleft.xpm";
	if (m == 2)
		game->img.path = "./sprites/sonicdown.xpm";
	if (m == 3)
		game->img.path = "./sprites/sonicup.xpm";
	if (m == 4 || m == 5 || m == 6 || m == 7)
		game->img.path = "./sprites/s_t.xpm";
}

void	perso_moov(t_data *game, int m)
{
	floor(game, m);
	sprites_exit(game, m);
	sprites_moov(game, m);
	game->img.path = mlx_xpm_file_to_image(game->mlx.ptr, \
	game->img.path, &game->img.width, &game->img.height);
	if (!game->img.path)
		ft_handlerror(9);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, \
		game->img.path, game->hook.x * 64, game->hook.y * 64);
	ft_printf("%d\n", game->hook.i++);
}
