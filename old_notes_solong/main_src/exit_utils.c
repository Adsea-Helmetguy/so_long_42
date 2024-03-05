/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:03:45 by mlow              #+#    #+#             */
/*   Updated: 2023/12/06 00:20:26 by mlow             ###   ########.fr       */
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
void	print_message(char *message, int exit_code)
{
	perror(message);
	exit(exit_code);
}
*/
void	end_exit(char *message, int exit_code, t_game *game)
{
	close(game->map.fd);
	print_message(message, exit_code);
}

void	free_end_exit(char *message, int exit_code, t_game *game, char **str)
{
//	int	array;
	
//	array = -1;
	if (*str)
	{
		free(*str);
		str = NULL;
	}
/*
	if (exit_code == 2)
	{
		if (game->map.row)
		{
			while (game->map.row[++array])
				free(game->map.row[array]);
			free(game->map.row);
		}
		array = -1;
		if (game->map.grid)
		{
			while (game->map.grid[++array])
				free(game->map.grid[array]);
			free(game->map.grid);
		}
	}
*/
	close(game->map.fd);
	print_message(message, 1);
}

int	x_close_window(t_game *game)
{
	int	array;
	
	array = -1;
	if (game->map.row)
	{
		while (game->map.row[++array])
			free(game->map.row[array]);
		free(game->map.row);
	}
	array = -1;
	if (game->map.grid)
	{
		while (game->map.grid[++array])
			free(game->map.grid[array]);
		free(game->map.grid);
		free_sprites(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	end_exit("Quitting game.\n", 0, game);
	return (0);
}

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->map.coin);
	mlx_destroy_image(game->mlx_ptr, game->map.wall);
	mlx_destroy_image(game->mlx_ptr, game->player.start);
	mlx_destroy_image(game->mlx_ptr, game->map.empty);
	mlx_destroy_image(game->mlx_ptr, game->map.door_exit);
}

void	*game_checkerror_exit(char *message, t_game *game)
{
	if (game->map.error_code != 0)
	{
		ft_printf("ERROR!! ");
		ft_printf("%s", message);
		ft_printf(" error_code != 0\n");
		return (NULL);
	}
}
