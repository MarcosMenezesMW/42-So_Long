/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mameneze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:05:29 by mameneze          #+#    #+#             */
/*   Updated: 2021/08/17 22:08:04 by mameneze         ###   ########.fr       */
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

typedef struct s_movement{
    int move_y;
    int move_x;
}               t_movement;

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct s_vars{
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct s_gamestructure {
    t_data      data;
    t_vars      vars;
    t_movement  movement;
    char    *relative_path;
    int     img_width;
    int     img_height;   
}              t_game;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
    *(unsigned int*)dst = color;
}

int close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(3);
}

int	key_hook(int keycode, t_game *game)
{
    if (keycode == ESC)
        close(&game->vars);
    if (keycode == UP)
        game->movement.move_y -= 10;
    if (keycode == DOWN)
        game->data.img = mlx_xpm_file_to_image(game->vars.mlx, game->relative_path, &game->img_width, &game->img_height);
        game->movement.move_y += 10;
    if (keycode == LEFT)
        game->movement.move_x -= 10;
    if (keycode == RIGHT)
        game->movement.move_x += 10;
}

int draw_square(t_game *game)
{
    int x = 0;
    int y = 0;
    my_mlx_pixel_put(&game->data, ++x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, ++x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, ++x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, ++x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, ++y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, ++y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, ++y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, ++y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, --x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, --x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, --x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, --x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, --y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, --y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, --y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, --y, 0x00FF0000);
    my_mlx_pixel_put(&game->data, x, y, 0x00FF0000);
}


int render_next_frame(t_game *game)
{
    mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->data.img, game->movement.move_x , game->movement.move_y);  
}

int main ()
{
    t_game  game;
    
    int i;
    int j;
    void *img;

    game.relative_path = "./teste.xpm";
    
    game.vars.mlx = mlx_init();
    game.vars.win = mlx_new_window(game.vars.mlx, 800, 600, "Hello World");
    //game.data.img = mlx_new_image(game.vars.mlx, 5, 5);
    
    //game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel, &game.data.line_length, &game.data.endian);
    //draw_square(&game);
    
    mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.data.img, 5, 5);    
    mlx_loop(game.vars.mlx);

}