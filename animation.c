/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 23:23:25 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/03 23:52:37 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate_char(t_game *game)
{
	if (game->hero.animate > 30000)
	{
		unload_sprites(game);
		load_sprites(game);
		image_to_window(game);
		game->hero.s_pos++;
		if (game->hero.s_pos == 2)
			game->hero.s_pos = 0;
		game->hero.animate = 0;
	}
	if (game->clct.animate > 10000)
	{
		unload_sprites(game);
		load_sprites(game);
		image_to_window(game);
		game->clct.s_pos++;
		game->enemy.s_pos++;
		if (game->clct.s_pos == 4)
			game->clct.s_pos = 0;
		if (game->enemy.s_pos == 3)
			game->enemy.s_pos = 0;
		game->clct.animate = 0;
	}
	if (game->enemy.animate > 20000)
		game->enemy.animate = 0;
	game->hero.animate++;
	game->clct.animate++;
	game->enemy.animate++;
	return (0);
}

int animate_game(t_game *game)
{
	animate_char(game);
	enemy_patrol(game);
	return (0);
}