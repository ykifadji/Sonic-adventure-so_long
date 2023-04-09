/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:49:22 by ykifadji          #+#    #+#             */
/*   Updated: 2023/04/04 07:57:51 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_path(char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == 'C' || map[j][i] == 'E')
				ft_handlerror(4);
		free(map[j]);
	}
	free(map);
}

static void	around(char **map, int j, int i)
{
	if (map[j][i + 1] != '1' && map[j][i + 1] != 'X')
		map[j][i + 1] = '|';
	if (map[j][i - 1] != '1' && map[j][i - 1] != 'X')
		map[j][i - 1] = '|';
	if (map[j + 1][i] != '1' && map[j + 1][i] != 'X')
		map[j + 1][i] = '|';
	if (map[j - 1][i] != '1' && map[j - 1][i] != 'X')
		map[j - 1][i] = '|';
}

static char	**ft_mapcpy(t_data *game)
{
	int		j;
	char	**map;

	map = ft_calloc((game->line + 1), sizeof(char *));
	j = -1;
	while (game->map[++j])
		map[j] = ft_strdup(game->map[j]);
	return (map);
}

void	path(t_data *game)
{
	int		j;
	int		i;
	char	**map;

	j = -1;
	map = ft_mapcpy(game);
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'P' || map[j][i] == '|')
			{
				map[j][i] = 'X';
				around(map, j, i);
				j = 0;
				break ;
			}
		}
	}
	check_path(map);
}
