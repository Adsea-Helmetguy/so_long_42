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

#include "../includes/so_long.h"

void	move_up_movement(t_game *game, int x, int y)
{
	if (game->map.row[y - 1][x] == 'C')
	{
		game->score += 1;
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y - 1][x] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);
	}
	else if (game->map.row[y - 1][x] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
		return ;
	}
	game->map.row[y][x] = '0';
	game->map.row[y - 1][x] = 'P';
	game->player_position = RIGHT;
	put_player(game, x, y - 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->map.empty, (x * 100), (y * 100));
}

void	move_left_movement(t_game *game, int x, int y)
{
	if (game->map.row[y][x - 1] == 'C')
	{
		game->score += 1;
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y][x - 1] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);
	}
	else if (game->map.row[y][x - 1] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
		return ;
	}
	game->map.row[y][x] = '0';
	game->map.row[y][x - 1] = 'P';
	game->player_position = RIGHT;
	put_player(game, x - 1, y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->map.empty, (x * 100), (y * 100));
}

void	move_down_movement(t_game *game, int x, int y)
{
	if (game->map.row[y + 1][x] == 'C')
	{
		game->score += 1;
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y + 1][x] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);
	}
	else if (game->map.row[y + 1][x] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
		return ;
	}
	game->map.row[y][x] = '0';
	game->map.row[y + 1][x] = 'P';
	game->player_position = RIGHT;
	put_player(game, x, y + 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->map.empty, (x * 100), (y * 100));
}

void	move_right_movement(t_game *game, int x, int y)
{
	if (game->map.row[y][x + 1] == 'C')
	{
		game->score += 1;
		ft_printf("Coin GETTO!!! x%d\n", game->score);
	}
	else if (game->map.row[y][x + 1] == 'E' && 
			game->score == game->map.coin_exist)
	{
		ft_printf("You f**king donkey\n");
		ft_printf("Total Steps taken %d\n", game->player.steps_taken);
		x_close_window(game);
	}
	else if (game->map.row[y][x + 1] == 'E')
	{
		ft_printf("Get all the coins first you donkey\n");
		return ;
	}
	game->map.row[y][x] = '0';
	game->map.row[y][x + 1] = 'P';
	game->player_position = RIGHT;
	put_player(game, x + 1, y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->map.empty, (x * 100), (y * 100));
}

void	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->player.start, (x * 100), (y * 100));
	game->player.x = x * 100;
	game->player.y = y * 100;
}
