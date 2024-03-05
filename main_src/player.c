/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:34:01 by mlow              #+#    #+#             */
/*   Updated: 2023/12/11 21:34:31 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	where_player(t_game *game)
{
	int	width;
	int	height;

	height = -1;
	while (game->map.row[++height])
	{
		width = -1;
		while (game->map.row[height][++width])
		{
			if (game->map.row[height][width] == 'P')
			{
				game->player.start_x = width;
				game->player.start_y = height;
				return ;
			}
		}
	}
	end_exit("Player can't be found @ where_player", 2, game);
}

void	find_player(t_game *game, int width, int height)
{
	game->player.y = 0;
	game->player.start = mlx_xpm_file_to_image(game->mlx_ptr, PACMAN_XPM, 
			&(game->player.size_width), &(game->player.size_height));
	if (game->player.start == NULL)
		end_exit("player unable to find XPM file", 2, game);
	while (game->map.row[++height])
	{
		game->player.x = 0;
		width = -1;
		while (game->map.row[height][++width])
		{
			if (game->map.row[height][width] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->player.start, game->player.x, game->player.y);
				break ;
			}
			game->player.x += 100;
		}
		if (game->map.row[height][width] == 'P')
			break ;
		game->player.y += 100;
	}
}

void	update_position_player(t_game *game, int keycode)
{
	int		x;
	int		y;
	char	*moves;

	x = game->player.x / 100;
	y = game->player.y / 100;
	if (keycode == W_KEY && game->map.row[y - 1][x] != '1')
		move_up_movement(game, x, y);
	else if (keycode == A_KEY && game->map.row[y][x - 1] != '1')
		move_left_movement(game, x, y);
	else if (keycode == S_KEY && game->map.row[y + 1][x] != '1')
		move_down_movement(game, x, y);
	else if (keycode == D_KEY && game->map.row[y][x + 1] != '1')
		move_right_movement(game, x, y);
	game->player.steps_taken += 1;
	ft_printf("Steps taken %d\n", game->player.steps_taken);
}
