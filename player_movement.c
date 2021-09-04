/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:30:49 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/04 00:17:43 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_player(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	move_up(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;
	
	if (game->hero.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') - game->col - 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->clct.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->clct.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_down(t_game *game)
{
	char	*playercurrentpos;
	char	*playernextpos;

	if (game->hero.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		playernextpos = get_player(game->map, 'P') + game->col + 1;
		if (*playernextpos == '0' || *playernextpos == 'C'
			|| (*playernextpos == 'E' && game->clct.qtcollect == -1))
		{
			if (*playernextpos == 'C')
				game->clct.qtcollect--;
			if (*playernextpos == 'E')
				finished(game);
			*playercurrentpos = '0';
			*playernextpos = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_left(t_game *game)
{
	char	*playercurrentpos;

	if (game->hero.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P') - 1;
		if (playercurrentpos [0] == '0' || playercurrentpos[0] == 'C'
			|| (playercurrentpos[0] == 'E' && game->clct.qtcollect == -1))
		{
			if (playercurrentpos[0] == 'C')
				game->clct.qtcollect--;
			if (playercurrentpos[0] == 'E')
				finished(game);
			playercurrentpos[1] = '0';
			playercurrentpos[0] = 'P';
			game->scr.scr++;
		}
	}
	return (0);
}

int	move_right(t_game *game)
{
	char	*playercurrentpos;

	if (game->hero.qthero > 0)
	{
		playercurrentpos = get_player(game->map, 'P');
		if (playercurrentpos [1] == '0' || playercurrentpos[1] == 'C'
			|| (playercurrentpos[1] == 'E' && game->clct.qtcollect == -1))
		{
			if (playercurrentpos[1] == 'C')
				game->clct.qtcollect--;
			if (playercurrentpos[1] == 'E')
				finished(game);
			playercurrentpos[0] = '0';
			playercurrentpos[1] = 'P';
			game->scr.scr++;
		}
	}		
	return (0);
}
