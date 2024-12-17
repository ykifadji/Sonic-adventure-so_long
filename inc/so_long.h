/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:13:19 by ykifadji          #+#    #+#             */
/*   Updated: 2024/12/17 08:03:22 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <../minilibx-opengl/mlx.h>
# include <../minilibx-linux/mlx.h>
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

typedef struct s_hook
{
	int	y;
	int	x;
	int	c;
	int	xe;
	int	ye;
	int	i;
}	t_hook;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	int		size_x;
	int		size_y;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_hook	hook;
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
void	pos_p(t_data *game);
int		ft_exit(t_data *game);

int		key_hook(int keycode, t_data *game);
void	right(t_data *game);
void	left(t_data *game);
void	down(t_data *game);
void	up(t_data *game);
void	perso_moov(t_data *game, int x);

#endif