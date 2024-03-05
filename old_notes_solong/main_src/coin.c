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

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

void	coin_coin(t_game *game)
{
	int	width;
	int	height;
	int	x;
	int	y;

	height = -1;
	y = 0;
	game->map.coin_exist = 0;
	game->map.coin = mlx_xpm_file_to_image(game->mlx_ptr, COIN_XPM, 
			&(game->img.x), &(game->img.y));
	if (game->map.coin == NULL)
		end_exit("coin_coin unable to find XPM file", 1, game);
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
	game->score = 0;
//	ft_printf("Coins after check_vaild_path: %d\n", game->map.coin_exist);
}
