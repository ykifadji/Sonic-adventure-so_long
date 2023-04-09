/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 07:35:09 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/26 08:35:25 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		ft_handlerror(6);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_handlerror(7);
	game.argv1 = argv[1];
	game_init(&game, 0);
	return (0);
}
