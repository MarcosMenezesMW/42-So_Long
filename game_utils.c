/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:21:09 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/22 20:26:36 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game *game)
{
	int		fd;
	int		eof;
	char	*map;

	eof = 1;
	game->line = 1;
	game->mapfile = "./maps/testemap";
	game->filesize = 0;
	fd = open(game->mapfile, O_RDONLY);
	while (eof > 0)
	{
		map = malloc(1);
		eof = read(fd, map, 1);
		if (*map == '\n')
			game->line++;
		game->filesize++;
		free (map);
	}
	game->column = (game->filesize - game->line) / game->line;
	game->filesize--;
	game->map = malloc(game->filesize);
	close(fd);
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;

	fd = open(game->mapfile, O_RDONLY);
	read(fd, game->map, game->filesize + 1);
	close(fd);
	return (0);
}
