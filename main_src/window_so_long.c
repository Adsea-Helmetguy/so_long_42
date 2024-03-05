/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_so_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:50:56 by mlow              #+#    #+#             */
/*   Updated: 2023/12/03 17:26:58 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_all(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	wallcheck_path(game, col, row);
	playerexit_path(game, col, row);
	coin_path(game, col, row);
	game->map.map_coin = 0;
	game->map.door_exist = 0;
	game->map.player_exist = 0;
	game->player.steps_taken = 0;
	ft_printf("\n\nSteps taken = %d\n", game->player.steps_taken);
}

void	*init_game(char **argv)
{
	t_game		game;

	open_testmap(&game, argv[1]);
	if (game.map.error_code != 0)
		end_exit("open_testmap error @ init_game", 2, &game);
	where_player(&game);
	check_all(&game);
	check_vaild_path(&game, &game.map.grid, game.player.start_x, 
		game.player.start_y);
	new_playerexitcoin_path(&game);
	game.mlx_ptr = mlx_init();
	invalid_window_size(&game);
	image_testmap(&game);
	if (game.map.error_code != 0)
		return (game_checkerror_exit("image_testmap", &game));
	mlx_key_hook(game.win_ptr, keyhook, &game);
	mlx_hook(game.win_ptr, 17, 0, x_close_window, &game);
	mlx_loop(game.mlx_ptr);
	close(game.map.fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error, not enough arguements");
		return (1);
	}
	else if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
	{
		ft_printf("File must end with .ber extension.\n");
		return (0);
	}
	init_game(argv);
	return (0);
}
//type ./so_long "./assets/ber_maps/valid2.ber"
