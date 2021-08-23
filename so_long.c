/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:40:50 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/22 23:46:02 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_player(char *s)
{
	while (*s)
	{
		if (*s == 'P')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n_value;
	int		i;

	n_value = n;
	i = ft_intlen(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n_value == 0)
		str[i] = '0';
	while (n_value > 0)
	{
		str[i--] = n_value % 10 + '0';
		n_value /= 10;
	}
	return (str);
}

int	imgtoPrint(t_game *game, int size, int column, int line)
{	
	if (game->map[size] == '0')
		put_floor(game, column, line);
	if (game->map[size] == '1')
		put_wall(game, column, line);
	if (game->map[size] == 'P')
		put_player(game, column, line);
	if (game->map[size] == 'C')
		put_collectible(game, column, line);
	if (game->map[size] == 'E')
		put_exit(game, column, line);
	return (1);
}

int	image_to_window(t_game *game)
{
	int		line;
	int		column;
	int		totalsize;
	char	*score;

	score = malloc(ft_intlen(game->score.score));
	totalsize = 0;
	line = 0;
	column = 0;
	game->totalCollectible = 0;
	while (totalsize < game->filesize)
	{
		column += imgtoPrint(game, totalsize, column, line);
		if (game->map[totalsize] == '\n')
		{
			column = 0;
			line++;
		}
		totalsize++;
	}
	score = ft_itoa(game->score.score);
	mlx_string_put(game->vars.mlx, game->vars.mlx_window, 500, 100, 255, score);
	free(score);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int		range;
	char	*playerlastposition;
	char	*getplayerposition;

	if (keycode == ESC)
		endgame(game);
	if (keycode == UP)
	{
		getplayerposition = get_player(game->map) - game->column - 1;
		playerlastposition = get_player(game->map);
		if (*getplayerposition != '1' && *getplayerposition != 'E')
		{
			*playerlastposition = '0';
			*getplayerposition = 'P';
			game->score.score++;
		}
	}
	if (keycode == DOWN)
	{
		getplayerposition = get_player(game->map) + game->column + 1;
		playerlastposition = get_player(game->map);
		if (*getplayerposition != '1' && *getplayerposition != 'E')
		{
			*playerlastposition = '0';
			*getplayerposition = 'P';
			game->score.score++;
		}
	}
	if (keycode == LEFT)
	{
		getplayerposition = get_player(game->map) - 1;
		if (getplayerposition [0] != '1' && getplayerposition[0] != 'E')
		{
			getplayerposition[1] = '0';
			getplayerposition[0] = 'P';
			game->score.score++;
		}
	}
	if (keycode == RIGHT)
	{
		getplayerposition = get_player(game->map);
		if (getplayerposition [1] != '1' && getplayerposition[1] != 'E')
		{
			getplayerposition[0] = '0';
			getplayerposition[1] = 'P';
			game->score.score++;
		}
	}
	if (keycode == RIGHT || keycode == LEFT || keycode == UP || keycode == DOWN)
	{
		image_to_window(game);
		printf("Steps = %d\n", game->score.score);
	}
	return (0);
}

int	main()
{
	t_game	game;
	int		mapwidth;
	int		mapheight;

	game.score.score = 0;
	load_map(&game);
	read_map(&game);
	load_files(&game);
	game.vars.mlx = mlx_init();
	load_sprites(&game);
	mapwidth = game.column * game.wall.imgWidth;
	mapheight = game.line * game.wall.imgHeight;
	game.vars.mlx_window = mlx_new_window(game.vars.mlx,
			mapwidth, mapheight, "teste");
	image_to_window(&game);
	mlx_key_hook(game.vars.mlx_window, key_hook, &game);
	mlx_hook(game.vars.mlx_window, 33, 1L << 2, endgame, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
