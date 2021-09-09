/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:21:09 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/08 22:11:17 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
static int	check_square(t_game *game)
{
	if (game->col == game->lin)
		return (printf(ERROR_DEF SQREERROR), exit(0), 0);
	return (0);
}

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
		return (printf("Error: Invalid file descriptor!\n"), exit(0), 0);
	while (eof > 0)
	{
		map = calloc(1, 1);
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
	check_square(game);
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;

	fd = open(game->mapf, O_RDONLY);
	read(fd, game->map, game->flsz);
	close(fd);
	return (0);
}

int	check_win_condition(t_game *game)
{
	if (game->clct.qtcollect == 0)
	{
		printf("You can now leave the map!\n");
		game->clct.qtcollect = -1;
	}
	return (0);
}

int	check_extension(t_game *game)
{
	int	size;

	size = ft_strlen(game->mapf) - 4;
	if (game->mapf[size] == '.' && game->mapf[size + 1] == 'b'
		&& game->mapf[size + 2] == 'e' && game->mapf[size + 3] == 'r')
		return (0);
	return (printf("Invalid extension. Must be a \".ber\" file\n"),
		exit(0), 0);
}
