/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:22:02 by ykifadji          #+#    #+#             */
/*   Updated: 2023/03/28 10:52:02 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handlerror(int x)
{
	if (x == 0)
		write(2, "Error\nSize of the map is invalid.\n", 35);
	else if (x == 1)
		write(2, "Error\nThe elements in the map are invalid.\n", 44);
	else if (x == 2)
		write(2, "Error\nPlease set the walls correctly.\n", 39);
	else if (x == 3)
		write(2, "Error\nIt takes more than 3 lines.\n", 25);
	else if (x == 4)
		write(2, "Error\nThe path is impossible.\n", 31);
	else if (x == 5)
		write(2, "Error\nFile not found.\n", 23);
	else if (x == 6)
		write(2, "Error\nWrong numbers of arguments.\n", 35);
	else if (x == 7)
		write(2, "Error\nBad extensions name.\n", 28);
	else if (x == 8)
		write(2, "Error\nUnrecognize the elements.\n", 33);
	else if (x == 9)
		write(2, "Error\nWRONG PATH !\n", 20);
	exit(1);
}

int	linelen(t_data *game, int fd)
{
	int	i;

	game->map[0] = get_next_line(fd);
	if (game->map[0] == NULL)
		return (0);
	i = 0;
	while (game->map[0][i] != '\n' && game->map[0][i])
		i++;
	free(game->map[0]);
	return (i);
}

void	map(t_data *game, char *argv)
{
	int	fd;
	int	j;

	j = -1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_handlerror(5);
	game->map = malloc((game->line + 1) * sizeof(char *));
	if (!game->map)
		return ;
	game->len = linelen(game, fd);
	close(fd);
	fd = open(argv, O_RDONLY);
	while (j == -1 || game->map[j])
	{
		j++;
		game->map[j] = get_next_line(fd);
	}
	close(fd);
}

void	ft_maplen(t_data *game, char *argv)
{
	char	*str;
	int		fd;

	game->line = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		game->line++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	ft_freemap(t_data *game)
{
	int	j;

	j = -1;
	while (game->map[++j])
		free(game->map[j]);
	free(game->map);
}
