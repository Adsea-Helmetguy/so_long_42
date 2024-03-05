/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:48 by mlow              #+#    #+#             */
/*   Updated: 2023/11/21 18:00:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../other_srcs/libft_project/libft.h"
# include "../other_srcs/printf_project/libftprintf.h"
# include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

//Images used for the maps
# define RICK_XPM "./assets/images/rick.xpm"
# define WALL_XPM "./assets/images/wall.xpm"
# define COIN_XPM "./assets/images/coin.xpm"
# define EXIT_XPM "./assets/images/exit.xpm"
# define EXITOPEN_XPM "./assets/images/exitopen.xpm"
# define PACMAN_XPM "./assets/images/pacman.xpm"

//define the keys
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC 65307

//define value
# define WIDTH 100
# define HEIGHT 100
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

//strut
//wall, collectables, emptyspace.
typedef struct s_map {
	int		fd;
	int		height;
	int		width;
	int		x;
	int		y;
	int		screen_x;
	int		screen_y;
	int		error_code;
	char	**row;
	char	**grid;
	void	*empty;
	void	*wall;
	void	*coin;
	int		coin_exist;
	int		map_coin;
	int		door_exist;
	int		wall_check;
	int		player_exist;
	void	*door_exit;
}				t_map;

typedef struct s_img {
	int	x;
	int	y;
}				t_img;

typedef struct s_player {
	int		size_width;
	int		size_height;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	void	*start;
	void	**location;
	int		steps_taken;
}				t_player;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_map		map;
	t_player	player;
	t_img		img;
	int			score;
	int			moves;
	int			player_position;
	int			img_width;
	int			img_height;
}				t_game;

//exit_utils.c
void	end_exit(char *message, int exit_code, t_game *game);
void	free_end_exit(char *message, int exit_code, t_game *game, char **str);
void	free_sprites(t_game *game);
void	*game_checkerror_exit(char *message, t_game *game);
int		x_close_window(t_game *game);

//message.c
void	print_message(char *message, int exit_code);

//For mouse & key hooks
int		keyhook(int keycode, t_game *game);
int		mousehook(int keycode, t_game *game);

//invalid.c
void	invalid_checker(t_game *game, char *vaild_char);
void	invalid_no_01cep(t_game *game, char *vaild_char);
void	invalid_window_size(t_game *game);

//map usage?
void	image_testmap(t_game *game);
char	*obtain_str_testmap(t_game *game);
void	xy_testmap(t_game *game);
void	errorcheck_testmap(t_game *game, char **string_map);
void	open_testmap(t_game *game, char *map_path);

//empty.c file
void	background_empty(t_game *game, int width, int height);

//wall.c
void	wall_wall(t_game *game, int width, int height);

//coin.c
void	coin_coin(t_game *game, int width, int height);

//door.c
void	door(t_game *game, int width, int height);

//player.c
void	where_player(t_game *game);
void	find_player(t_game *game, int width, int height);
void	update_position_player(t_game *game, int keycode);

//player_movements.c
void	move_up_movement(t_game *game, int x, int y);
void	move_left_movement(t_game *game, int x, int y);
void	move_down_movement(t_game *game, int x, int y);
void	move_right_movement(t_game *game, int x, int y);
void	put_player(t_game *game, int x, int y);

//vaild_path.c
void	wallcheck_path(t_game *game, int col, int row);
void	playerexit_path(t_game *game, int col, int row);
void	coin_path(t_game *game, int col, int row);
void	new_playerexitcoin_path(t_game *game);
void	check_vaild_path(t_game *game, char ***grid, int x, int y);
void	check_all(t_game *game);

//For (main) windows_so_long use;
void	*init_game(char **argv);

#endif
/*
#include <unistd.h> // for fork() / execve() / access()
#include <stdio.h> // for printf()
#include <stdlib.h> // exit()
#include <fcntl.h> //open()
#include <sys/wait.h> // wait() / waitpid()
#include <sys/types.h> //for wait() / fork() / pid_t() / wait() / waitpid() 
#include <errno.h> // for perror() 
*/
