/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:19:17 by mameneze          #+#    #+#             */
/*   Updated: 2021/09/05 18:05:31 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "./minilibx/mlx.h"

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
# define PARAMERROR	"Invalid parameter!\n"
# define WALL_ERR   "Map should be surrounded by walls!\n"
# define SQREERROR	"Map cannot be a square\n"
# define WINMSG		"You Won! Score: "
# define LOSEMSG	"You Lost!\nSCORE: "
# define LEAVE		"You may now close the game.\n"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		maph;
	int		mapw;
}				t_vars;

enum e_hero {
	HERO_UP,
	HERO_STILL,
};

enum e_collect {
	COLLECT_FRONT,
	COLLECT_LEFT,
	COLLECT_SIDE,
	COLLECT_RIGHT,
};

enum e_enemy {
	ENEMY_F1,
	ENEMY_F2,
	ENEMY_F3,
};

typedef struct s_sprite{
	char	*path;
	void	*img;
	int		img_wid;
	int		img_hght;
}				t_sprite;

typedef struct s_Hero{
	char	*path[2];
	void	*img;
	int		img_wid;
	int		img_hght;
	int		s_pos;
	int		qthero;
	int		animate;
}				t_hero;

typedef struct s_collect{
	char	*path[4];
	void	*img;
	int		img_wid;
	int		img_hght;
	int		s_pos;
	int		qtcollect;
	int		animate;
}				t_collect;

typedef struct s_enemy{
	char			*path[3];
	void			*img;
	char			*pos;
	int				img_wid;
	int				img_hght;
	int				s_pos;
	int				qtd;
	int				anim;
	int				chk;
	int				drct;
}				t_enemy;

typedef struct s_score{
	int		scr;
}				t_score;

typedef struct s_game{
	t_vars		vrs;
	t_score		scr;
	t_hero		hero;
	t_enemy		enemy;
	t_collect	clct;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	ext;
	int			qtext;
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
int		put_enemy(t_game *game, int x, int y);
int		enemy_patrol(t_game *game);
int		animate_game(t_game *game);
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
int		check_win_condition(t_game *game);
int		finished(t_game *game);

#endif