/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:43:01 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/22 23:43:15 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->wall.img, (x * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	return (0);
}

int	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->floor.img, (x * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	return (0);
}

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->floor.img, (x * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->hero.img, (x * game->wall.imgWidth + 25),
		(y * game->wall.imgHeight));
	return (0);
}

int	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->floor.img, (x * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->collectible.img, (x * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	return (0);
}

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window,
		game->exit.img, (y * game->wall.imgWidth),
		(y * game->wall.imgHeight));
	return (0);
}
