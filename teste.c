/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:40:50 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/18 00:07:07 by mameneze         ###   ########.fr       */
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


typedef struct s_game{
    t_vars      vars;
    t_data      data;
    t_movement  movement;
    char        *path;
    char        *pathup;
    char        *pathleft;
    char        *pathright;
    char        *frst;
    int         iw;
    int         ih;
    int         iw2;
    int         ih2;
    int         faceup;
    int         facedown;
    int         faceleft;
    int         faceright;
}              t_game;

int endgame(t_game *game)
{
    mlx_destroy_image(game->vars.mlx, game->data.img);
    mlx_destroy_window(game->vars.mlx, game->vars.mlx_window);
}

int	key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
        endgame(game);
    if (keycode == UP && game->movement.move_y > 100)
    {
        game->facedown = 0;
        game->faceup = 1;
        game->faceleft = 0;
        game->faceright = 0;
        game->movement.move_y -= 50;
    }
    if (keycode == DOWN && game->movement.move_y < 391)
    {
        game->facedown = 1;
        game->faceup = 0;
        game->faceleft = 0;
        game->faceright = 0;
        game->movement.move_y += 50;
    }
    if (keycode == LEFT && game->movement.move_x > 95)
    {
        game->facedown = 0;
        game->faceup = 0;
        game->faceleft = 1;
        game->faceright = 0;
        game->movement.move_x -= 50;
    }
    if (keycode == RIGHT && game->movement.move_x < 450)
    {
        game->facedown = 0;
        game->faceup = 0;
        game->faceleft = 0;
        game->faceright = 1;
        game->movement.move_x += 50;
    }
}

int reload_image(t_game *game)
{  
    mlx_destroy_image(game->vars.mlx, game->data.img);
    game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->frst, &game->iw2, &game->ih2);
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->data.img, 0, 0);
    if (game->facedown == 1)
    {
        mlx_destroy_image(game->vars.mlx, game->data.img);
        game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->path, &game->iw, &game->ih);
    }
    if (game->faceup == 1)
    {
        mlx_destroy_image(game->vars.mlx, game->data.img);
        game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathup, &game->iw, &game->ih);
    } 
    if (game->faceleft == 1)
    {
        mlx_destroy_image(game->vars.mlx, game->data.img);
        game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathleft, &game->iw, &game->ih);
    } 
    if (game->faceright == 1)
    {
        mlx_destroy_image(game->vars.mlx, game->data.img);
        game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->pathright, &game->iw, &game->ih);
    } 
    
}

int render_next_frame(t_game *game)
{
    reload_image(game);
    mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_window, game->data.img, game->movement.move_x, game->movement.move_y);  
}

int main()
{
    t_game  game;
    
    game.path = "./teste.xpm";
    game.pathup = "./testeup.xpm";
    game.pathleft = "./testeleft.xpm";
    game.pathright = "./testeright.xpm";
    game.frst = "./frst.xpm";
    game.movement.move_x = 100;
    game.movement.move_y = 100;
    game.facedown = 1;
    game.faceup = 0;
    game.faceleft = 0;
    game.faceright = 0;
    game.vars.mlx = mlx_init();
    game.vars.mlx_window = mlx_new_window(game.vars.mlx, 550, 600, "teste");
    game.data.img = mlx_xpm_file_to_image(game.vars.mlx, game.frst, &game.iw, &game.ih);
    mlx_loop_hook(game.vars.mlx, render_next_frame, &game);
    mlx_key_hook(game.vars.mlx_window, key_hook, &game);
    mlx_loop(game.vars.mlx);
}