/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:41:18 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/22 19:44:26 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_files(t_game *game)
{
	game->hero.path = "./imgs/teste.xpm";
	game->floor.path = "./imgs/floor.xpm";
	game->wall.path = "./imgs/tilesetTest.xpm";
	game->collectible.path = "./imgs/collectible.xpm";
	game->exit.path = "./imgs/exit.xpm";
	return (0);
}

int	load_sprites(t_game *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, game->hero.path,
			&game->hero.imgWidth, &game->hero.imgHeight);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->wall.path,
			&game->wall.imgWidth, &game->wall.imgHeight);
	game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, game->floor.path,
			&game->floor.imgWidth, &game->floor.imgHeight);
	game->collectible.img = mlx_xpm_file_to_image(game->vars.mlx,
			game->collectible.path, &game->collectible.imgWidth,
			&game->collectible.imgHeight);
	game->exit.img = mlx_xpm_file_to_image(game->vars.mlx, game->exit.path,
			&game->exit.imgWidth, &game->exit.imgHeight);
	return (0);
}

int	unload_sprites(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->hero.img);
	mlx_destroy_image(game->vars.mlx, game->floor.img);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->collectible.img);
	mlx_destroy_image(game->vars.mlx, game->exit.img);
	return (0);
}

int	endgame(t_game *game)
{
	unload_sprites(game);
	mlx_destroy_window(game->vars.mlx, game->vars.mlx_window);
	exit(0);
	return (0);
}
