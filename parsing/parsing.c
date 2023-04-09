/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:51:53 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/23 15:48:39 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_data *game)
{
	int	j;
	int	i;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i] && (j == 0 || j == game->line - 1))
			if (game->map[j][i] != '1' && game->map[j][i] != '\n')
				ft_handlerror(2);
		if ((game->map[j][0] != '1' \
			|| game->map[j][game->len - 1] != '1') && game->map[j][i])
			ft_handlerror(2);
	}
}

void	parsing(t_data *game, char *argv)
{
	int		j;
	int		len;

	ft_maplen(game, argv);
	map(game, argv);
	if (game->line < 3)
		ft_handlerror(3);
	j = -1;
	while (++j < game->line)
	{
		len = ft_strlen(game->map[j]);
		if (game->map[j][len - 1] == '\n')
			len = ft_strlen(game->map[j]) - 1;
		if (len != game->len)
			ft_handlerror(0);
	}
	check_wall(game);
	if (elements(game, argv) == 0)
		ft_handlerror(1);
	path(game);
}

void	check(char *str, t_data *game)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			game->p++;
		else if (str[i] == 'E')
			game->e++;
		else if (str[i] == 'C')
			game->c++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n')
			ft_handlerror(8);
		i++;
	}
}

int	elements(t_data *game, char *argv)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	game->p = 0;
	game->e = 0;
	game->c = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		check(str, game);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (game->p != 1 || game->e != 1 || game->c < 1)
		return (0);
	else
		return (1);
}
