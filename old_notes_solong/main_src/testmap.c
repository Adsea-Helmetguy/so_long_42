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

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>

/*
typedef struct	s_map {
	int	fd;
	void	*wall;
	void	*coin;
	void	*emptyspace;
	void	*exit;
	int		img_width;
	int		img_height;
}				t_map;
*/

//map_path == argv[1]
/* 
  reason why we use &game(*game) here is because we want the game here
   to also be modified.
   Whenever you need to modify the game variable passed to another
   function, you need to deference that pointer "&game" to ensure
   that the original location is modified.
   thus-> game->map.fd cause (*game).map.fd.
*/
//
/*
1111111111
1P00000CE1
1111111111
*/
//
//example: ./so_long assets/ber_maps/valid1.ber
//two things left, close window button x, and resize windows;
// mlx_get_screen_size
// window_x & window_y

void	image_testmap(t_game *game)
{
//	ft_printf("Height before img %d\n", game->map.height);
//	ft_printf("width before img %d\n", game->map.width);
	background_empty(game);//00000
	wall_wall(game);//1111111111
	coin_coin(game);//CCCCCCCCCC
	door(game);//EEEEEEEEEE
}

void	xy_testmap(t_game *game)
{
	int	height;
	int	width;
	
	height = 0;
	width = 0;
//	ft_printf("game->map.height= \n");// starts and seg here if map empty
	while (game->map.row[height][width] != '\0')
		width++;
//		ft_printf("%c\n", game->map.row[height][width++]);
	while (game->map.row[height])
		height++;
//		ft_printf("game->map.row %s\n", game->map.row[height++]);
	game->map.height = height * 100;
	game->map.y = height;
	game->map.width = width * 100;
	game->map.x = width;
//	ft_printf("game->map.height value = %d\n", game->map.y);
//	ft_printf("game->map.width value = %d\n", game->map.x);
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
	int	index;
	
	readmap = (char *)malloc(sizeof(char) * 1);
	if (!readmap)
		return (NULL);
//		end_exit("malloc_testmap error", 1, game);
	index = 1;
	readmap[0] = '\0';
	while (index != 0)
	{
		newline = get_next_line(game->map.fd);
//		ft_printf("\n\n\n\nnewline is=%s\n", newline);
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
//		ft_printf("readmap= \n%s", readmap);
	}
	if (!readmap[0])
		free_end_exit("MAP IS EMPTY!!!", 1, game, &readmap);
	//over here, we do double pointer e.g **readmap2
	// with that we then, put the map row by row using ft_split.
	//get the wdith and height from there. -done for all-
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

void	open_testmap(t_game *game, char *map_path)//why this one just void?
{	
	char	*readmap;
	
	game->map.fd = open(map_path, O_RDONLY);// ../assets/maps/valid1.ber
	if (game->map.fd < 0)
		end_exit("Unable to open map.fd, path not found", 1, game);
	readmap = obtain_str_testmap(game);
//	if (!readmap)
//		free_end_exit("malloc_testmap error", 1, game, &readmap);
//	ft_printf("\n---Test start---\n\nstring_testmap: \n%s\n", readmap);
	errorcheck_testmap(game, &readmap);//to check for errors before ft_split
	game->map.row = ft_split(readmap, '\n');
	game->map.grid = ft_split(readmap, '\n');
	free(readmap);
	invalid_checker(game, "01CEP");
	xy_testmap(game);
	if (game->map.error_code != 0)
		end_exit("Error_code != 0 with xy_testmap\n", 1, game);
}
	//what does map.full_line do?-Yun Xuan
	//malloc and get_next_line gamemap [0][0] = line[0]
	// == '1' (corner wall)
/*
	map.emptyspace = '0';
	map.wall = '1';
	map.coin = 'C';
	map.exit = 'E';
	map.player = 'P';
*/	
