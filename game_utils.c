/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:21:09 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/28 17:16:38 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game *game)
{
	int		fd;
	int		eof;
	char	*map;

	eof = 1;
	game->lin = 1;
	game->flsz = 0;
	fd = open(game->mapf, O_RDONLY);
	if (fd < 0)
		return (printf("Error: Invalid file descriptor"), exit(0), 0);
	while (eof > 0)
	{
		map = malloc(1);
		eof = read(fd, map, 1);
		if (*map == '\n')
			game->lin++;
		game->flsz++;
		free (map);
	}
	game->col = (game->flsz - game->lin) / game->lin;
	game->flsz--;
	game->map = malloc(game->flsz);
	close(fd);
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;

	fd = open(game->mapf, O_RDONLY);
	read(fd, game->map, game->flsz + 1);
	close(fd);
	return (0);
}
