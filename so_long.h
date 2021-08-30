/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:19:17 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/28 19:25:17 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>

# define UP         119 
# define DOWN       115
# define LEFT       97
# define RIGHT      100
# define ESC        65307
# define ERROR_DEF  "Error\n"
# define OPLRERROR  "Need a player position on the map!\n"
# define MRPLRERROR "Only 1 player allowed!\n"
# define CLCTERROR  "Need at least one collectible!\n"
# define EXTERROR   "Need at least one exit!\n"
# define VLDMERROR  "Not a valid map!\n"
# define WALL_ERR   "Map Should be Surrounded by Walls!\n"

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_sprite{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
}				t_sprite;

typedef struct s_score{
	int		scr;
}				t_score;

typedef struct s_game{
	t_vars		vrs;
	t_score		scr;
	t_sprite	hero;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	collect;
	t_sprite	ext;
	int			qtcollect;
	int			qtext;
	int			qthero;
	int			flsz;
	int			col;
	int			lin;
	char		*map;
	char		*mapf;
}				t_game;

char	*get_player(char *s, char c);
int		load_sprites(t_game *game);
int		unload_sprites(t_game *game);
int		load_files(t_game *game);
int		load_map(t_game *game);
int		read_map(t_game *game);
int		endgame(t_game *game);
int		put_wall(t_game *game, int x, int y);
int		put_floor(t_game *game, int x, int y);
int		put_player(t_game *game, int x, int y);
int		put_collectible(t_game *game, int x, int y);
int		put_exit(t_game *game, int x, int y);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		image_to_window(t_game *game);
int		imgtoPrint(t_game *game, int size, int column, int line);
int		ft_strlen(char *s);
int		check_extension(t_game *game);
int		check_walling(t_game *game);
int		level_validation(t_game *game);

#endif