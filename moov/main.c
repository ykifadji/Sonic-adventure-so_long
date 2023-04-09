/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:35:09 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/27 09:04:52 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_handlerror(6);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_handlerror(7);
	parsing(&game, argv[1]);
	game.mlx.ptr = mlx_init();
	if (!game.mlx.ptr)
		return (1);
	game.mlx.size_x = game.len * 64;
	game.mlx.size_y = game.line * 64;
	game.mlx.win = mlx_new_window(game.mlx.ptr, game.mlx.size_x, \
		game.mlx.size_y, "Sonic");
	background(&game);
	game.hook.c = 0;
	pos_p(&game);
	game.hook.i = 1;
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
