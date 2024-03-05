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

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

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
					break;
				index++;
			}
			if (!vaild_char[index])
				free_end_exit("INVAILD_checker", 1, game, &vaild_char);
			x++;
			
		}
		y++;
	}
}
/*
** Get the current screen size (because macOS is sheit)
**
** @param	void *mlx_ptr	the mlx instance;
** @param	int  *sizex		the screen width;
** @param	int  *sizey		the screen height
** @return	int				has no return value (bc).
*/
//int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void	invalid_window_size(t_game *game)
{
	int	window_x;
	int	window_y;

	window_x = game->map.width;
	window_y = game->map.height;
	game->map.screen_x = 0;
	game->map.screen_y = 0;
	mlx_get_screen_size(game->mlx_ptr, &game->map.screen_x, &game->map.screen_y);
//	ft_printf("\nvalue of window_x= %d and window_y= %d\n", window_x, window_y);
//	ft_printf("value of screen_x= %d and screen_y= %d\n", game->map.screen_x, game->map.screen_y);
	if (window_x > game->map.screen_x || window_y > game->map.screen_y)
		end_exit("Map size is too large.\n", 1, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width,
			game->map.height, "testmap");
//	game->display.ptr = mlx_new_image(game->mlx_ptr, window_x, window_y);
//	game->display.x = window_x;
//	game->display.y = window_y;
//	get_sprite_info(&game->display);
}









