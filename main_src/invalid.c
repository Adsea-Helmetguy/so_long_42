/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:06:19 by mlow              #+#    #+#             */
/*   Updated: 2023/12/20 19:06:48 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	invalid_checker(t_game *game, char *vaild_char)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (game->map.row[y])
	{
		x = 0;
		while (game->map.row[y][x])
		{
			index = 0;
			while (vaild_char[index])
			{
				if (game->map.row[y][x] == vaild_char[index])
					break ;
				index++;
			}
			if (!vaild_char[index])
				end_exit("INVAILD_checker", 2, game);
			x++;
		}
		y++;
	}
}

void	invalid_no_01cep(t_game *game, char *valid_char)
{
	int	x;
	int	y;
	int	index;
	int	valid_counter;

	index = 0;
	while (valid_char[index])
	{
		y = 0;
		valid_counter = 0;
		while (game->map.row[y])
		{
			x = 0;
			while (game->map.row[y][x])
			{
				if (game->map.row[y][x] == valid_char[index])
					valid_counter++;
				x++;
			}
			y++;
		}
		if (valid_counter == 0)
			end_exit("INVAILD_NO_01CEP", 2, game);
		index++;
	}
}

void	invalid_window_size(t_game *game)
{
	int	window_x;
	int	window_y;

	window_x = game->map.width;
	window_y = game->map.height;
	game->map.screen_x = 0;
	game->map.screen_y = 0;
	mlx_get_screen_size(game->mlx_ptr, &game->map.screen_x, 
		&game->map.screen_y);
	if (window_x > game->map.screen_x || window_y > game->map.screen_y)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		end_exit("Map size is too large.\n", 2, game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width,
			game->map.height, "testmap");
}
