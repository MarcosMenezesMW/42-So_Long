/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:40:50 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/28 17:34:57 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	char	*playerlastposition;
	char	*getplayerposition;

	if (keycode == ESC)
		endgame(game);
	if (keycode == UP)
		move_up(game);
	if (keycode == DOWN)
		move_down(game);
	if (keycode == LEFT)
		move_left(game);
	if (keycode == RIGHT)
		move_right(game);
	if (keycode == RIGHT || keycode == LEFT || keycode == UP || keycode == DOWN)
	{
		image_to_window(game);
		printf("Steps = %d\n", game->scr.scr);
	}
	return (0);
}

int	init_game(t_game *game)
{
	game->scr.scr = 0;
	game->qtcollect = 0;
	game->qtext = 0;
	game->qthero = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		mapwidth;
	int		mapheight;

	game.mapf = argv[1];
	check_extension(&game);
	load_map(&game);
	read_map(&game);
	init_game(&game);
	level_validation(&game);
	check_walling(&game);
	load_files(&game);
	game.vrs.mlx = mlx_init();
	load_sprites(&game);
	mapwidth = game.col * game.wall.img_wid;
	mapheight = game.lin * game.wall.img_hght;
	game.vrs.win = mlx_new_window(game.vrs.mlx,
			mapwidth, mapheight, "SO_LONG");
	image_to_window(&game);
	mlx_key_hook(game.vrs.win, key_hook, &game);
	mlx_hook(game.vrs.win, 33, 1L << 2, endgame, &game);
	mlx_loop(game.vrs.mlx);
	return (0);
}
