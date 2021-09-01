/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:40:50 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/31 22:33:06 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_game *game)
{
	static int	check_steps;

	check_steps = game->scr.scr;
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
		image_to_window(game);
	if (game->scr.scr > check_steps)
		printf("Steps = %d\n", game->scr.scr);
	return (0);
}

static int	init_game(t_game *game)
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

	if (argc != 2)
		return (printf(ERROR_DEF "Invalid parameters!\n"), 0);
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
	game.vrs.mapw = game.col * game.wall.img_wid;
	game.vrs.maph = game.lin * game.wall.img_hght;
	game.vrs.win = mlx_new_window(game.vrs.mlx,
			game.vrs.mapw, game.vrs.maph, "SO_LONG");
	image_to_window(&game);
	mlx_key_hook(game.vrs.win, key_hook, &game);
	mlx_hook(game.vrs.win, 33, 1L << 2, endgame, &game);
	mlx_loop(game.vrs.mlx);
	return (0);
}
