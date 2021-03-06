/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:43:01 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/08 23:39:02 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->wall.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int	put_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->hero.img, (x * game->wall.img_wid + 5),
		(y * game->wall.img_hght));
	return (0);
}

int	put_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->clct.img, (x * game->wall.img_wid + 12),
		(y * game->wall.img_hght + 12));
	return (0);
}

int	put_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->ext.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}
