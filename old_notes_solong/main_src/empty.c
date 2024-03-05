/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:13:59 by mlow              #+#    #+#             */
/*   Updated: 2023/12/11 19:14:01 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

//for the 0000000000
void	background_empty(t_game *game)
{
	int	width;
	int	height;
	int	x;
	int	y;

	height = -1;
	y = 0;
	game->map.empty = mlx_xpm_file_to_image(game->mlx_ptr, RICK_XPM, 
			&(game->img.x), &(game->img.y));
	if (game->map.empty == NULL)
		end_exit("background_empty unable to find XPM file", 1, game);
	while (game->map.row[++height])
	{
		x = 0;
		width = -1;
		while (game->map.row[height][++width])
		{
			if (game->map.row[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->map.empty, x, y);
			x += 100;
		}
		y += 100;
	}
}
