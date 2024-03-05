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

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

void	wallcheck_path(t_game *game, int col, int row)
{
	int	y;

	y = (game->map.height / 100) -1;
	while (game->map.row[0][col] && game->map.row[0][col] == '1')
		col++;
	if (game->map.row[0][col] && game->map.row[0][col] != '1')
		end_exit("One of row[0] map column isn't '1'!\n", 1, game);
	col = 0;
	while (game->map.row[y][col] && game->map.row[y][col] == '1')
		col++;
	if (game->map.row[y][col] && game->map.row[y][col] != '1')
		end_exit("One of last row map column isn't '1'!\n", 1, game);
	while (game->map.row[row] && game->map.row[row][0] == '1')
		row++;
	if (game->map.row[row] && game->map.row[row][0] != '1')
		end_exit("One of last row map column isn't '1'!\n", 1, game);
	row = 0;
	while (game->map.row[row] && game->map.row[row][col - 1] == '1')
		row++;
	if (game->map.row[row] && game->map.row[row][col - 1] != '1')
		end_exit("One of last row map column isn't '1'!\n", 1, game);
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
//		ft_printf("counters P = %d  &  E = %d\n", p_counter, e_counter);
		while (game->map.row[row][col])
		{
			if (game->map.row[row][col] == 'P')
			{
//				ft_printf("FOUND U LOLOLOL\nLOLOLOL\n");
				p_counter++;
			}	
			else if (game->map.row[row][col] == 'E')
			{
//				ft_printf("FOUND U22 LOLOLOL\nLOLOLOL\n");
				e_counter++;
			}
			col++;
		}
		col = 0;
	}

	if (p_counter != 1 || e_counter != 1) 
		end_exit("Check your players and exit again!\n", 1, game);
	row = -1;
}

void	coin_path(t_game *game, int col, int row)
{
	int	c_counter;
	
	c_counter = 0;
	while (game->map.row[++row])
	{
//		ft_printf("counters c = %d\n", c_counter);
		while (game->map.row[row][col])
		{
			if (game->map.row[row][col] == 'C')
				c_counter++;
			col++;
		}
		col = 0;
	}
	if (c_counter < 1)
		end_exit("Need minimum 1 coin!!\n", 1, game);
}

//
//
/*
void	invaild_path(game, col, row)
{
	int	x;
	int	y;
	char	*valid;
	int	accepted;
	
	x = 0;
	y = 0;
	accepted = 0;
	valid = (char *)malloc(sizeof(char) * 5);
	if (!valid)
		return (NULL);
	valid = "01CEP";
	while (game->map.row[y])
	{
		while (game->map.row[y][x] != valid[accepted])
			accepted++;
		if (game->map.row[y][x] == valid[accepted])
			
	}
}
*/
//
/*
if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;
 0
01111111111
 1000000001
 1P00000CE1
 1000000001
 1111111111
 
 	1) Wall -> '1';
	2) empty -> '0';
	3) coin -> 'C';-----
	4) door -> 'E'----
	& 5) player -> 'P';----
*/

void	new_playerexitcoin_path(t_game *game)
{
	if (game->map.door_exist != 1)
		end_exit("Doors != 1, remove or add till 1.", 1, game);
//	ft_printf("total map.door_exist @ vaildpath = %d\n", game->map.door_exist);
	if (game->map.player_exist != 1)
		end_exit("more than 1player.", 1, game);
//	ft_printf("total map.player_check @ vaildpath = %d\n", game->map.player_exist);
	if (game->map.map_coin == game->map.coin_exist)
		end_exit("map.coin_exist != map.coin_exist.", 1, game);
//	ft_printf("total map.coin_exist @ vaildpath = %d\n", game->map.coin_exist);
}

void	check_vaild_path(t_game *game, char ***grid, int x, int y)
{
	int	col = -1;

	if ((y - 1) < 0 || (x - 1) < 0 || (y + 1) >= (game->map.height / 100)
		|| (x + 1) >= (game->map.width / 100)|| (*grid)[y][x] == '1')//player start point, why not == 'P'?
		return ;
	if ((*grid)[y][x] == 'C')
		game->map.map_coin++;
	else if ((*grid)[y][x] == 'E')
		game->map.door_exist++;
	else if ((*grid)[y][x] == 'P')
		game->map.player_exist++;
//	ft_printf("\n value of exit in door_exist = %d\n\n", game->map.door_exist);
//	ft_printf("\n value of coins in coin_exist = %d\n\n", game->map.map_coin);
//	ft_printf("\n no of player in player_exist = %d\n\n", game->map.player_exist);
	(*grid)[y][x] = '1';// to ensure that the grid check wont go back to that part;
	check_vaild_path(game, grid, x, y - 1);
	check_vaild_path(game, grid, x, y + 1);
	check_vaild_path(game, grid, x - 1, y);
	check_vaild_path(game, grid, x + 1, y);
}
