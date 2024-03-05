/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:05:29 by mlow              #+#    #+#             */
/*   Updated: 2023/12/11 21:05:32 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	coin_coin(t_game *game, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	game->map.coin_exist = 0;
	game->map.coin = mlx_xpm_file_to_image(game->mlx_ptr, COIN_XPM, 
			&(game->img.x), &(game->img.y));
	if (game->map.coin == NULL)
		end_exit("coin_coin unable to find XPM file", 2, game);
	while (game->map.row[++height])
	{
		x = 0;
		width = -1;
		while (game->map.row[height][++width])
		{
			if (game->map.row[height][width] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
					game->map.coin, x, y);
				game->map.coin_exist++;
			}
			x += 100;
		}
		y += 100;
	}
}
