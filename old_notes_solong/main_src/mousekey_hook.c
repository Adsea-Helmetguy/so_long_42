/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousekey_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:30 by mlow              #+#    #+#             */
/*   Updated: 2023/12/05 15:48:38 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

/*
You pressed keycode No:119 which is w
You pressed keycode No:97 which is a
You pressed keycode No:115 which is s
You pressed keycode No:100 which is d
*/
int	keyhook(int keycode, t_game *game)
{
//	if (keycode != 65293) //enter key remove spam
//		ft_printf("You pressed keycode No:%d which is %c\n", keycode, keycode);
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY)
		update_position_player(game, keycode);
	else if (keycode == 65307)
	{
		x_close_window(game);
//		close_window(keycode, game);
	}
	return (0);
}
/*
int	mousehook(int keycode, t_game *game)
{
	char	print_keycode;
	
	print_keycode = keycode + '0';
	ft_printf("You pressed keycode No:%d which is %c\n", keycode, print_keycode);
	return (0);
}
*/
