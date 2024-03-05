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

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

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
	end_exit("Player can't be found @ where_player", 1, game);
}

void	find_player(t_game *game)
{
	int	width;
	int	height;

	height = -1;
	game->player.y = 0;
	game->player.start = mlx_xpm_file_to_image(game->mlx_ptr, PACMAN_XPM, 
			&(game->player.size_width), &(game->player.size_height));
	if (game->player.start == NULL)
		end_exit("player unable to find XPM file", 1, game);
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
				break;
			}
			game->player.x += 100;
		}
		if (game->map.row[height][width] == 'P')
			break;
		game->player.y += 100;
	}
}

void	update_position_player(t_game *game, int keycode)
{
	int	x;
	int	y;
	char	*moves;
	
	x = game->player.x / 100;//current player position
	y = game->player.y / 100;//current player position
//	ft_printf("value of x: %d & y: %d\n", x, y);
	if (keycode == W_KEY && game->map.row[y - 1][x] != '1')//if w is pressed
		move_up_movement(game, x, y);
	else if (keycode == A_KEY && game->map.row[y][x - 1] != '1')//if a is pressed
		move_left_movement(game, x, y);	
	else if (keycode == S_KEY && game->map.row[y + 1][x] != '1')//if s is pressed
		move_down_movement(game, x, y);
	else if (keycode == D_KEY && game->map.row[y][x + 1] != '1')// if d is pressed
		move_right_movement(game, x, y);
	game->player.steps_taken += 1;
	ft_printf("Steps taken %d\n", game->player.steps_taken);
}



//notes:
/*
int	game_process(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->movement += movement(data, -1, 0);
	else if (keycode == S || keycode == DOWN)
		data->movement += movement(data, 1, 0);
	else if (keycode == A || keycode == LEFT)
		data->movement += movement(data, 0, -1);
	else if (keycode == D || keycode == RIGHT)
		data->movement += movement(data, 0, 1);
	else if (keycode == ESC)
		end_game(data, "\nESC");
	map_display(data->mlx, data->window, data->data_sprite, data->map);
	ft_printf("Step(s): %d\n", data->movement);
	return (0);
}

static void	move_player(t_data *data, int y, int x, int *pos)
{
	data->map[pos[0]][pos[1]] = '0';
	data->map[pos[0] + y][pos[1] + x] = 'P';
}

static int	*player_position(t_data *data)
{
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		end_game(data, "Error\nWhere is Player?");
	pos[0] = 0;
	while (data->map[pos[0]])
	{
		pos[1] = 0;
		while (data->map[pos[0]][pos[1]])
		{
			if (data->map[pos[0]][pos[1]] == 'P')
				return (pos);
			pos[1]++;
		}
		pos[0]++;
	}
	ft_free(1, &pos);
	return (NULL);
}

static int	movement(t_data *data, int y, int x)
{
	int	*pos;

	pos = player_position(data);
	if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == '0')
		move_player(data, y, x, pos);
	else if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == 'C')
	{
		move_player(data, y, x, pos);
		data->collected++;
	}
	else if (data->map[pos[0] + y][pos[1] + x] && data->map[pos[0] + y][pos[1] \
		+ x] == 'E')
	{
		if (data->collected == data->coin)
		{
			ft_free(1, &pos);
			end_game(data, "\nSUCCES");
		}
	}
	ft_free(1, &pos);
	return (1);
}

*/
