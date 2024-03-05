/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:50:56 by mlow              #+#    #+#             */
/*   Updated: 2023/12/03 17:26:58 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

void	check_all(t_game *game)
{
	int	col;
	int	row;
	
	col = 0;
	row = 0;
	wallcheck_path(game, col, row);
	playerexit_path(game, col, row);
	coin_path(game, col, row);
	game->map.map_coin = 0;
	game->map.door_exist = 0;
	game->map.player_exist = 0;
	game->player.steps_taken = 0;
	ft_printf("\n\nSteps taken = %d\n", game->player.steps_taken);
}

//type ./so_long "./assets/ber_maps/valid2.ber"
void	*init_game(char **argv)
{
	t_game		game;

	open_testmap(&game, argv[1]); //terminal you will call the map path
	if (game.map.error_code != 0)
		end_exit("open_testmap error at window_so_long", 1, &game);
//	ft_printf("After find_player(game), width = %d, height = %d\n", 
//		game.player.x, game.player.y);
	where_player(&game);
	check_all(&game);
//	ft_printf("\n\n\nmap height= %d & map_width= %d\n\n\n", game.map.height, game.map.width);
//	ft_printf("\ngame->map.coin_exist= %d\n", game.map.coin_exist);
	check_vaild_path(&game, &game.map.grid, game.player.start_x, game.player.start_y);
//	ft_printf("\ngame->map.map_coin_exist= %d\n", game.map.map_coin);
	new_playerexitcoin_path(&game);
	game.mlx_ptr = mlx_init();
	invalid_window_size(&game);
	image_testmap(&game);
	find_player(&game);
//	ft_printf("After image_testmap value(1): %d\n", game.map.error_code);
	if (game.map.error_code != 0)
		return (game_checkerror_exit("image_testmap", &game));
	mlx_key_hook(game.win_ptr, keyhook, &game);
//	mlx_mouse_hook(game.win_ptr, mousehook, &game);
	mlx_hook(game.win_ptr, 17, 0, x_close_window, &game);//close the window and free
	mlx_loop(game.mlx_ptr);
	close(game.map.fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error, not enough arguements");
		return (1);
	}
/*
	else if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4));
	{
		print_msg("File must end with .ber extension.\n", 2);
		return (0);
	}
*/
	init_game(argv);
	return (0);
}

//This will persist through multiple calls if 
//it is a pointer, so use that to your advantage!
/*
int	render_next_frame(void *YourStruct);
{
	if (game->map.enemies > 0)
		check_enemy(game, &game->enemy, game->map.grid,
			&game->enemy.direction);
	render_map(game, &game->map);
	player_action(game);
	render_to_window(game, &game->display, 0, 0);
	update_move_count(game);
	return (0);
}
*/
//
/*
t_vars	*vars;

vars->window
-same as-
(*vars).window

without pointer just put '.' to reference to list inside.
*/
//
/*
int	main(void)
{
//	void	*mlx_ptr;
//	void	*mlx_window;
//	t_vars	vars;
//	t_vars2	vars2;
//	t_image	img;
//	int	img_width;
//	int	img_height;

//	img.mlx_ptr = mlx_init();
//	img_width = 600;
//	img_height = 600;
//	mlx_window = mlx_new_window(mlx_ptr, 500, 500, "Tester_window");
//	vars.mlx_ptr = mlx_init();
//	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 500, 500, "Tester_window");
//	vars2.mlx_ptr = mlx_init();
//	vars2.win_ptr = mlx_new_window(vars2.mlx_ptr, 700, 700, "Tester_window");
//	mlx_hook(vars.win_ptr, 2, 1L<<0, close_window, &vars); //its a void, no return
//	mlx_key_hook(vars.win_ptr, keyhook, &vars);
//	mlx_mouse_hook(vars.win_ptr, mousehook, &vars);
//	mlx_key_hook(vars2.win_ptr, keyhook, &vars2);
//	mlx_mouse_hook(vars2.win_ptr, mousehook, &vars2);
//	mlx_loop(vars.mlx_ptr);
//	mlx_loop_hook(vars2.mlx_ptr, render_next_frame, &vars2);

	img.win_ptr = mlx_new_window(img.mlx_ptr, 800, 800, "MiniLibX PNG Example");
	img.relative_path = "./images/sand.xpm";
	img.img_ptr = mlx_xpm_file_to_image(img.mlx_ptr, img.relative_path, &(img.img_width), &(img.img_height));
	if (img.img_ptr == NULL)
	{
		ft_printf("error test img_ptr");
		exit(1);
	}
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(img.mlx_ptr);

	return (0);
}
*/
//
//
//
//
//
//
//
/*
  "3)"
  Hooking into events:
  void mlx_hook(mlx_win_list_t *win_ptr, int x11_event, int x11_mask, int (*f)(), void *param)

  gonna use ->  "mlx_new_hook = mlx_hook(vars.win_ptr, 2, 1L<<0, close, &vars);"
  
*/
//
//
//
//
//
//
/*"2)"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}
*/
//
//
//      void *mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title);
/*
int	main(void)
{
	int	print;
	int	xside;
	int	yside;
	t_data	image;	
	
	image.img = mlx_new_image(mlx_ptr, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
//RGB COLOURS 0xTTRRGGBB
	xside = 200;
	yside = 200;
	print = -1;
	while (++print != 5)
	{
		my_mlx_pixel_put(&image, xside, yside, 0x00FF0000);
		xside += 10;
	}
	while (print++ != 10)
	{
		my_mlx_pixel_put(&image, xside, yside, 0x0000FF00);
		yside += 10;
	}
	xside = 200;
	yside = 200;
	while (print++ != 16)
	{
		my_mlx_pixel_put(&image, xside, yside, 0x0000FF00);
		yside += 10;
	}
	yside -= 10;
	while (print++ != 21)
	{
		xside += 10;
		my_mlx_pixel_put(&image, xside, yside, 0x00FF0000);
	}
*/
	//image of the screen and determines where on the screen they pop out.
	//more than one mlx_pixel put will create another small pixel
//	mlx_put_image_to_window(mlx_ptr, mlx_window, image.img, 0, 0);
