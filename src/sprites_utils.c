/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:41:18 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/05 21:14:52 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_files(t_game *game)
{
	game->hero.path = "./imgs/hero/heromo.xpm";
	game->floor.path = "./imgs/tileset/floor.xpm";
	game->wall.path = "./imgs/tileset/wall.xpm";
	game->ext.path = "./imgs/tileset/exit.xpm";
	game->clct.path = "./imgs/collectible/collectfront.xpm";
	return (0);
}

int	finished(t_game *game)
{
	printf(WINMSG "%d\n", game->scr.scr);
	return (endgame(game), 0);
}

int	load_sprites(t_game *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->vrs.mlx, game->hero.path,
			&game->hero.img_wid, &game->hero.img_hght);
	game->wall.img = mlx_xpm_file_to_image(game->vrs.mlx, game->wall.path,
			&game->wall.img_wid, &game->wall.img_hght);
	game->floor.img = mlx_xpm_file_to_image(game->vrs.mlx, game->floor.path,
			&game->floor.img_wid, &game->floor.img_hght);
	game->clct.img = mlx_xpm_file_to_image(game->vrs.mlx, game->clct.path,
			&game->clct.img_wid, &game->clct.img_hght);
	game->ext.img = mlx_xpm_file_to_image(game->vrs.mlx, game->ext.path,
			&game->ext.img_wid, &game->ext.img_hght);
	return (0);
}

int	unload_sprites(t_game *game)
{
	mlx_destroy_image(game->vrs.mlx, game->hero.img);
	mlx_destroy_image(game->vrs.mlx, game->floor.img);
	mlx_destroy_image(game->vrs.mlx, game->wall.img);
	mlx_destroy_image(game->vrs.mlx, game->clct.img);
	mlx_destroy_image(game->vrs.mlx, game->ext.img);
	return (0);
}

int	endgame(t_game *game)
{
	unload_sprites(game);
	mlx_destroy_window(game->vrs.mlx, game->vrs.win);
	exit(0);
	return (0);
}
