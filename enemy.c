/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:56:18 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/04 00:27:17 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_enemy(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->floor.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	mlx_put_image_to_window(game->vrs.mlx, game->vrs.win,
		game->enemy.img, (x * game->wall.img_wid),
		(y * game->wall.img_hght));
	return (0);
}

int enemy_patrol(t_game *game)
{
	char	*enemypos;
	char	*nextpos;

	enemypos = get_player(game->map, 'X');
	nextpos = get_player(game->map, 'X') + game->col 
	* game->enemy.direction + game->enemy.direction;
	if (*nextpos != '0' && *nextpos != 'P')
		game->enemy.direction *= -1;
	if(*nextpos == 'P' && game->enemy.animate > 20000)
	{
		printf(LOSEMSG "%d\n" LEAVE, game->scr.scr);
		game->hero.qthero = -1;
	}
	if ((*nextpos == '0' || *nextpos == 'P') && game->enemy.animate > 20000)
	{
		*enemypos = '0';
		*nextpos = 'X';
	}		
	return (0);
}