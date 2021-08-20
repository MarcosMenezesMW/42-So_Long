/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:40:50 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/19 22:25:58 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

#define UP 119 
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ESC 65307

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


typedef struct s_game{
    t_vars      vars;
    t_data      data;
    t_movement  movement;
    t_sprite    hero;
    t_sprite    wall;
    t_sprite    floor;
    t_sprite    collectible;
    t_sprite    exit;
    char        *path;
    char        *pathup;
    char        *pathleft;
    char        *pathright;
    int         faceup;
    int         facedown;
    int         faceleft;
    int         faceright;
}              t_game;

int unload_sprites(t_game *game)
{
    mlx_destroy_image(game->vars.mlx, game->hero.img);
    mlx_destroy_image(game->vars.mlx, game->floor.img);
    mlx_destroy_image(game->vars.mlx, game->wall.img);
    mlx_destroy_image(game->vars.mlx, game->collectible.img);
    mlx_destroy_image(game->vars.mlx, game->exit.img);
    return (0);
}
int endgame(t_game *game)
{
    unload_sprites(game);
    mlx_destroy_window(game->vars.mlx, game->vars.mlx_window);
    exit(0);
    return (0);
}

int	key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
        endgame(game);
//     if (keycode == UP && game->movement.move_y > 100)
//     {
//         game->facedown = 0;
//         game->faceup = 1;
//         game->faceleft = 0;
//         game->faceright = 0;
//         game->movement.move_y -= 50;
//     }
//     if (keycode == DOWN && game->movement.move_y < 391)
//     {
//         game->facedown = 1;
//         game->faceup = 0;
//         game->faceleft = 0;
//         game->faceright = 0;
//         game->movement.move_y += 50;
//     }
//     if (keycode == LEFT && game->movement.move_x > 95)
//     {
//         game->facedown = 0;
//         game->faceup = 0;
//         game->faceleft = 1;
//         game->faceright = 0;
//         game->movement.move_x -= 50;
//     }
//     if (keycode == RIGHT && game->movement.move_x < 450)
//     {
//         game->facedown = 0;
//         game->faceup = 0;
//         game->faceleft = 0;
//         game->faceright = 1;
//         game->movement.move_x += 50;
//     }
    return (0);
}

int load_sprites(t_game *game)
{
    game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, game->hero.path, &game->hero.imgWidth, &game->hero.imgHeight);
    game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->wall.path, &game->wall.imgWidth, &game->wall.imgHeight);
    game->floor.img = mlx_xpm_file_to_image(game->vars.mlx, game->floor.path, &game->floor.imgWidth, &game->floor.imgHeight);
    game->collectible.img = mlx_xpm_file_to_image(game->vars.mlx, game->collectible.path, &game->collectible.imgWidth, &game->collectible.imgHeight);
    game->exit.img = mlx_xpm_file_to_image(game->vars.mlx, game->exit.path, &game->exit.imgWidth, &game->exit.imgHeight);
    return (0);
}

int image_to_window(char map[15][15], t_game *game)
{
    int     line;
    int     column;
    int     linesize;

    linesize = game->wall.imgHeight;

    line = 0;
    while (line <= 6)
    {
        column = 0;

        while (column <= 14)
        {
            if (map[line][column] == '0')
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->floor.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
            if (map[line][column] == '1')
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->wall.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
            if (map[line][column] == 'P')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->floor.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->hero.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
            }
            if (map[line][column] == 'C')
            {
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->floor.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->collectible.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
            }
            if (map[line][column] == 'E')
                mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->exit.img, (column * game->wall.imgWidth),(line * game->wall.imgHeight));
            column++;
        }
        line++;
    }
    return (0);
}

// int reload_image(t_game *game)
// {  
//     mlx_destroy_image(game->vars.mlx, game->data.img);
//     game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->frst, &game->iw2, &game->ih2);
//     mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->data.img, 0, 0);
//     if (game->facedown == 1)
//     {
//         mlx_destroy_image(game->vars.mlx, game->data.img);
//         game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->path, &game->iw, &game->ih);
//     }
//     if (game->faceup == 1)
//     {
//         mlx_destroy_image(game->vars.mlx, game->data.img);
//         game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathup, &game->iw, &game->ih);
//     } 
//     if (game->faceleft == 1)
//     {
//         mlx_destroy_image(game->vars.mlx, game->data.img);
//         game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathleft, &game->iw, &game->ih);
//     } 
//     if (game->faceright == 1)
//     {
//         mlx_destroy_image(game->vars.mlx, game->data.img);
//         game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathright, &game->iw, &game->ih);
//     } 
    
// }

// int render_next_frame(t_game *game)
// {
//     reload_image(game);
//     mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->data.img, game->movement.move_x, game->movement.move_y);  
// }

int load_files(t_game *game)
{
    game->hero.path = "./imgs/teste.xpm";
    game->floor.path = "./imgs/floor.xpm";
    game->wall.path = "./imgs/tilesetTest.xpm";
    game->collectible.path = "./imgs/collectible.xpm";
    game->exit.path = "./imgs/exit.xpm";
    return (0);
}

int main()
{
    t_game  game;

    char    map[10][15] = {
        "111111111111111",
        "1E000C000000C01",
        "100000000000001",
        "1000000P0000001",
        "100000000000001",
        "10C000000000001",
        "111111111111111"
    };
    int mapwidth;
    int mapheight;

    load_files(&game);
    
    // game.path = "./teste.xpm";
    // game.pathup = "./testeup.xpm";
    // game.pathleft = "./testeleft.xpm";
    // game.pathright = "./testeright.xpm";
    //game.movement.move_x = 100;
    //game.movement.move_y = 100;
    //game.facedown = 1;
    // game.faceup = 0;
    // game.faceleft = 0;
    // game.faceright = 0;
    game.vars.mlx = mlx_init();
    load_sprites(&game);
    mapwidth = 15 * game.wall.imgWidth;
    mapheight = 7 * game.wall.imgHeight;
    game.vars.mlx_window = mlx_new_window(game.vars.mlx, mapwidth, mapheight, "teste");
    image_to_window(map, &game);
    // game.data.img = mlx_xpm_file_to_image(game.vars.mlx, game.frst, &game.iw, &game.ih);
    // mlx_loop_hook(game.vars.mlx, render_next_frame, &game);
    mlx_key_hook(game.vars.mlx_window, key_hook, &game);
    mlx_loop(game.vars.mlx);
}