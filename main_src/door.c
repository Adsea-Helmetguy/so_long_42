/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:14:29 by mlow              #+#    #+#             */
/*   Updated: 2023/12/11 19:14:29 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	door(t_game *game, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	game->map.door_exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT_XPM, 
			&(game->img.x), &(game->img.y));
	if (game->map.door_exit == NULL)
		end_exit("door unable to find XPM file", 2, game);
	while (game->map.row[++height])
	{
		x = 0;
		width = -1;
		while (game->map.row[height][++width])
		{
			if (game->map.row[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->map.door_exit, x, y);
			x += 100;
		}
		y += 100;
	}
	height = -1;
	width = -1;
}
