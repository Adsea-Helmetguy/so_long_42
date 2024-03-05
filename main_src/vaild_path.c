/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaild_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:48:39 by mlow              #+#    #+#             */
/*   Updated: 2023/12/14 14:50:09 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	wallcheck_path(t_game *game, int col, int row)
{
	int	y;

	y = (game->map.height / 100) - 1;
	while (game->map.row[0][col] && game->map.row[0][col] == '1')
		col++;
	if (game->map.row[0][col] && game->map.row[0][col] != '1')
		end_exit("One of row[0] map column isn't '1'!\n", 2, game);
	col = 0;
	while (game->map.row[y][col] && game->map.row[y][col] == '1')
		col++;
	if (game->map.row[y][col] && game->map.row[y][col] != '1')
		end_exit("One of last row map column isn't '1'!\n", 2, game);
	while (game->map.row[row] && game->map.row[row][0] == '1')
		row++;
	if (game->map.row[row] && game->map.row[row][0] != '1')
		end_exit("One of last row map column isn't '1'!\n", 2, game);
	row = 0;
	while (game->map.row[row] && game->map.row[row][col - 1] == '1')
		row++;
	if (game->map.row[row] && game->map.row[row][col - 1] != '1')
		end_exit("One of last row map column isn't '1'!\n", 2, game);
	col = 0;
	row = -1;
}

void	playerexit_path(t_game *game, int col, int row)
{
	int	p_counter;
	int	e_counter;

	p_counter = 0;
	e_counter = 0;
	while (game->map.row[++row] && p_counter <= 1 && e_counter <= 1)
	{
		while (game->map.row[row][col])
		{
			if (game->map.row[row][col] == 'P')
				p_counter++;
			else if (game->map.row[row][col] == 'E')
				e_counter++;
			col++;
		}
		col = 0;
	}
	if (p_counter != 1 || e_counter != 1) 
		end_exit("Check your players and exit again!\n", 2, game);
	row = -1;
}

void	coin_path(t_game *game, int col, int row)
{
	int	c_counter;

	c_counter = 0;
	while (game->map.row[++row])
	{
		while (game->map.row[row][col])
		{
			if (game->map.row[row][col] == 'C')
				c_counter++;
			col++;
		}
		col = 0;
	}
	if (c_counter < 1)
		end_exit("Need minimum 1 coin!!\n", 2, game);
}

void	new_playerexitcoin_path(t_game *game)
{
	if (game->map.door_exist != 1)
		end_exit("Doors != 1, remove or add till 1.", 2, game);
	if (game->map.player_exist != 1)
		end_exit("Player != 1.", 2, game);
	if (game->map.map_coin == game->map.coin_exist)
		end_exit("map.coin_exist != map.coin_exist.", 2, game);
}

void	check_vaild_path(t_game *game, char ***grid, int x, int y)
{
	int	col;

	col = -1;
	if ((y - 1) < 0 || (x - 1) < 0 || (y + 1) >= (game->map.height / 100)
		|| (x + 1) >= (game->map.width / 100) || (*grid)[y][x] == '1')
		return ;
	if ((*grid)[y][x] == 'C')
		game->map.map_coin++;
	else if ((*grid)[y][x] == 'E')
		game->map.door_exist++;
	else if ((*grid)[y][x] == 'P')
		game->map.player_exist++;
	(*grid)[y][x] = '1';
	check_vaild_path(game, grid, x, y - 1);
	check_vaild_path(game, grid, x, y + 1);
	check_vaild_path(game, grid, x - 1, y);
	check_vaild_path(game, grid, x + 1, y);
}
