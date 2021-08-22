/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 19:19:17 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/22 19:46:08 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define UP 119 
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct s_data{
    void *img;
    char *addr;
    int bpx;
    int ll;
    int endian;
}               t_data;

typedef struct s_vars{
    void *mlx;
    void *mlx_window;
}             t_vars;

typedef struct s_movement{
    int move_y;
    int move_x;
}               t_movement;

typedef struct s_sprite{
    char    *path;
    void    *img;
    int     imgWidth;
    int     imgHeight;
}               t_sprite;

typedef struct s_score{
    int     score;
}              t_score;


typedef struct s_game{
    t_vars      vars;
    t_data      data;
    t_score     score;
    t_movement  movement;
    t_sprite    hero;
    t_sprite    wall;
    t_sprite    floor;
    t_sprite    collectible;
    t_sprite    exit;
    int         totalCollectible;
    int         heroPosition;
    int         filesize;
    int         column;
    int         line;
    char        *map;
    char        *mapfile;
    char        *pathright;
    int         faceup;
    int         facedown;
    int         faceleft;
    int         faceright;
}              t_game;

int     load_sprites(t_game *game);
int     unload_sprites(t_game *game);
int     load_files(t_game *game);
int     load_map(t_game *game);
int     read_map(t_game *game);
int     endgame(t_game *game);

#endif