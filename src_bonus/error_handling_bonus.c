/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:02:51 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/09 21:53:42 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	frst_lst_line(t_game *game, int line, int col)
{
	if (line == 0)
		while (++col < game->col)
			if (game->map[col] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	if (line == game->lin)
	{
		col = ((game->flsz - 1) - (game->col - 1));
		while (++col < game->flsz)
			if (game->map[col] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
	}
	return (0);
}

int	check_walling(t_game *game)
{
	int	c;
	int	l;

	l = 0;
	while (l <= game->lin)
	{
		c = -1;
		frst_lst_line(game, l, c);
		if (l == 1)
			if (game->map[game->col + l] != '1'
				|| game->map[game->col * 2] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		if (l > 0 && l < game->lin)
			if (game->map[((game->col + 1) * l)] != '1'
				|| game->map[game->col - 1 + ((game->col + 1) * (l))] != '1')
				return (printf(ERROR_DEF WALL_ERR),
					free(game->map), exit(0), 0);
		l++;
	}
	return (0);
}

static int	check_invalid_chars(t_game *game, int pos)
{
	char	*valid_chars;

	valid_chars = "PEC10X\n";
	if (get_player(valid_chars, game->map[pos]) == NULL)
		return (printf(ERROR_DEF PARAMERROR), free(game->map), exit(0), 0);
	else
		return (0);
}

static int	check_map_content(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->flsz - 1)
	{
		check_invalid_chars(game, i);
		if (game->map[i] == 'P')
			game->hero.qthero++;
		if (game->map[i] == 'E')
			game->qtext++;
		if (game->map[i] == 'C')
			game->clct.qtcollect++;
		if (game->map[i] == 'X')
			game->enemy.qtd++;
		i++;
	}
	return (0);
}

int	level_validation(t_game *game)
{
	check_map_content(game);
	if (game->hero.qthero == 0)
		return (printf(ERROR_DEF OPLRERROR), free(game->map), exit(0), 0);
	if (game->hero.qthero > 1)
		return (printf(ERROR_DEF MRPLRERROR), free(game->map), exit(0), 0);
	if (game->clct.qtcollect == 0)
		return (printf(ERROR_DEF CLCTERROR), free(game->map), exit(0), 0);
	if (game->qtext == 0)
		return (printf(ERROR_DEF EXTERROR), free(game->map), exit(0), 0);
	return (0);
}
