/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:50:10 by mlow              #+#    #+#             */
/*   Updated: 2023/12/12 20:51:02 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

/*
1111111111
100000C001
1P0C000CE1
1000000001
1111111111
*/
//

void	move_up_movement(t_game *game, int x, int y)
{
	if (game->map.row[y - 1][x] == 'C') //if it's a coin, update score
	{
		game->score += 1;//coin_coin.c starts at 0
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y - 1][x] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);//how to import keycode value?
	}	
	else if (game->map.row[y - 1][x] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
			return ;
	}
//	game->moves += 1 //updates moves counter - check why we need
	game->map.row[y][x] = '0';//update map
	game->map.row[y - 1][x] = 'P';//update player location
	game->player_position = RIGHT;
	put_player(game, x, y - 1); //move the player, render player on the screen
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->map.empty, (x * 100), (y * 100)); // render empty space on last Player spot.
}

void	move_left_movement(t_game *game, int x, int y)
{
	if (game->map.row[y][x - 1] == 'C') //if it's a coin, update score
	{
		game->score += 1;//coin_coin.c starts at 0
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y][x - 1] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);//how to import keycode value?
	}	
	else if (game->map.row[y][x - 1] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
			return ;
	}
//	game->moves += 1 //updates moves counter - check why we need
	game->map.row[y][x] = '0';//update map
	game->map.row[y][x - 1] = 'P';//update player location
	game->player_position = RIGHT;
	put_player(game, x - 1, y); //move the player, render player on the screen
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->map.empty, (x * 100), (y * 100)); // render empty space on last Player spot.
}

void	move_down_movement(t_game *game, int x, int y)
{
	if (game->map.row[y + 1][x] == 'C') //if it's a coin, update score
	{
		game->score += 1;//coin_coin.c starts at 0
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y + 1][x] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);//how to import keycode value?
	}	
	else if (game->map.row[y + 1][x] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
			return ;
	}
	game->map.row[y][x] = '0';//update map
	game->map.row[y + 1][x] = 'P';//update player location
	game->player_position = RIGHT;
	put_player(game, x, y + 1); //move the player, render player on the screen
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->map.empty, (x * 100), (y * 100)); // render empty space on last Player spot.
}

void	move_right_movement(t_game *game, int x, int y)
{

	if (game->map.row[y][x + 1] == 'C') //if it's a coin, update score
	{
		game->score += 1;//coin_coin.c starts at 0
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y][x + 1] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);//how to import keycode value?
	}	
	else if (game->map.row[y][x + 1] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
			return ;
	}
//	game->moves += 1 //updates moves counter - check why we need
	game->map.row[y][x] = '0';//update map
	game->map.row[y][x + 1] = 'P';//update player location
	game->player_position = RIGHT;
	put_player(game, x + 1, y); //move the player, render player on the screen
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->map.empty, (x * 100), (y * 100)); // render empty space on last Player spot.
}


void	put_player(t_game *game, int x, int y)
{
//	if (game->player_position == RIGHT)
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
	game->player.start, (x * 100), (y * 100));
/*
	else if (game->player_position == LEFT)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_right_1, 0 + width * 100, 0 + (height * 100));
	else if (game->player_position == UP)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_right_1, 0 + width * 100, 0 + (height * 100));
	else if (game->player_position == DOWN)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_right_1, 0 + width * 100, 0 + (height * 100));
*/
	game->player.x = x * 100;
	game->player.y = y * 100;
}
