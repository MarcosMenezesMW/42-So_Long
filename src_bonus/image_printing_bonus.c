/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_printing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:33:38 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/08 23:38:50 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
	if (game->map[size] == 'X')
		put_enemy(game, column, line);
	return (1);
}

int	image_to_window(t_game *game)
{
	int		line;
	int		column;
	int		totalsize;
	char	*score;

	totalsize = 0;
	line = 0;
	column = 0;
	while (totalsize < game->flsz)
	{
		column += imgtoPrint(game, totalsize, column, line);
		if (game->map[totalsize++] == '\n')
		{
			column = 0;
			line++;
		}
	}
	check_win_condition(game);
	score = ft_itoa(game->scr.scr);
	mlx_string_put(game->vrs.mlx, game->vrs.win, (game->vrs.mapw / 2 - 50),
		25, create_trgb(0, 255, 255, 255), "SCORE: ");
	mlx_string_put(game->vrs.mlx, game->vrs.win, (game->vrs.mapw / 2),
		25, create_trgb(0, 255, 255, 255), score);
	free(score);
	return (0);
}
