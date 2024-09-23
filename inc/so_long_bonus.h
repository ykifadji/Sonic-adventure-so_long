/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:13:19 by ykifadji          #+#    #+#             */
/*   Updated: 2024/09/23 18:58:57 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <../minilibx/mlx.h>
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_hook
{
	int	y;
	int	x;
	int	c;
	int	xe;
	int	ye;
	int	i;
	int	a;
	int	k;
	int	v;
}	t_hook;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		frame;
	int		size_x;
	int		size_y;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*path;
	char	*grass;
	char	*element;
	char	*sonic_element;
	char	*wall;
	char	*col1;
	char	*col2;
	char	*col3;
	char	*col4;
	char	*enemy1;
	char	*enemy2;
	char	*enemy3;
	char	*enemy4;
	int		width;
	int		height;
	char	*nine;
	char	*eight;
	char	*seven;
	char	*six;
	char	*five;
	char	*four;
	char	*three;
	char	*two;
	char	*one;
	char	*zero;
}	t_img;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_hook	hook;
	t_pos	pos;
	int		start;
	char	*argv1;
	char	**map;
	int		line;
	int		p;
	int		e;
	int		c;
	int		len;
}	t_data;

void	parsing(t_data *game, char *argv);
void	map(t_data *game, char *argv);
void	ft_handlerror(int x);

void	check(char *str, t_data *game);
void	check_wall(t_data *game);
int		elements(t_data *game, char *argv);

void	ft_maplen(t_data *game, char *argv);
int		linelen(t_data *game, int fd);
void	ft_freemap(t_data *game);

void	path(t_data *game);

int		main(int argc, char **argv);
void	background(t_data *game);
void	set_enemy(t_data *game);
void	set_element(t_data *game);
void	pos_p(t_data *game);
int		ft_exit(t_data *game);

int		key_hook(int keycode, t_data *game);
void	right(t_data *game);
void	left(t_data *game);
void	down(t_data *game);
void	up(t_data *game);
void	perso_moov(t_data *game, int x);
void	ft_floor(t_data *game, int m);

void	path_col(t_data *game);
int		update(t_data *game);
void	startgame(t_data *game, int keycode);

void	enemy(t_data *game);
void	path_enemy(t_data *game);
void	reset_floor(t_data *game, int m);
void	endgame(t_data *game, int keycode);
void	game_init(t_data *game, int c);

void	ft_moves(t_data *game);
void	path_movess(t_data *game);
void	set_moves(t_data *game);
void	reset_wall(t_data *game, int x);
void	moves_three(t_data *game);

#endif