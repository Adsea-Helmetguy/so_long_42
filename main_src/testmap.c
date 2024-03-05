/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:10:17 by mlow              #+#    #+#             */
/*   Updated: 2023/12/06 01:21:16 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image_testmap(t_game *game)
{
	int	width;
	int	height;

	height = -1;
	width = -1;
	background_empty(game, width, height);
	wall_wall(game, width, height);
	height = -1;
	width = -1;
	coin_coin(game, width, height);
	game->score = 0;
	door(game, width, height);
	find_player(game, width, height);
}

void	xy_testmap(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (game->map.row[height][width] != '\0')
		width++;
	while (game->map.row[height])
		height++;
	game->map.height = height * 100;
	game->map.y = height;
	game->map.width = width * 100;
	game->map.x = width;
	if (game->map.height == 0 || game->map.width == 0)
		game->map.error_code = 1;
	else
		game->map.error_code = 0;
}

char	*obtain_str_testmap(t_game *game)
{
	char	*readmap;
	char	*tmp;
	char	*newline;
	int		index;

	readmap = (char *)malloc(sizeof(char) * 1);
	if (!readmap)
		return (NULL);
	index = 1;
	readmap[0] = '\0';
	while (index != 0)
	{
		newline = get_next_line(game->map.fd);
		index = ft_strlen(newline);
		if (newline)
		{
			tmp = readmap;
			readmap = ft_strjoin(tmp, newline);
			free(tmp);
			free(newline);
		}
		else
			index = 0;
	}
	return (readmap);
}

void	errorcheck_testmap(t_game *game, char **readmap)
{
	int	index;

	index = 0;
	while ((*readmap)[index])
	{
		if ((*readmap)[index] == '\n')
		{
			if ((*readmap)[index + 1] == '\n')
				free_end_exit("Empty line.", 1, game, readmap);
		}
		index++;
	}
}

void	open_testmap(t_game *game, char *map_path)
{
	char	*readmap;

	game->map.fd = open(map_path, O_RDONLY);
	if (game->map.fd < 0)
		end_exit("Unable to open map.fd, path not found", 1, game);
	readmap = obtain_str_testmap(game);
	if (!readmap[0])
		free_end_exit("MAP IS EMPTY!!!", 1, game, &readmap);
	errorcheck_testmap(game, &readmap);
	game->map.row = ft_split(readmap, '\n');
	game->map.grid = ft_split(readmap, '\n');
	free(readmap);
	invalid_checker(game, "01CEP");
	invalid_no_01cep(game, "01CEP");
	xy_testmap(game);
	if (game->map.error_code != 0)
		end_exit("Error_code != 0 with xy_testmap\n", 2, game);
}
