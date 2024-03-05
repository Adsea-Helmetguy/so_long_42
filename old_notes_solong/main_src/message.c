/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:13:22 by mlow              #+#    #+#             */
/*   Updated: 2023/12/06 00:19:16 by mlow             ###   ########.fr       */
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

void	print_message(char *message, int exit_code)
{
	if (exit_code != 0)
	{
		ft_printf("Error\n");
		perror(message); //occurs when there is an actual error
		exit(exit_code);
	}
	else
	{
		ft_printf("%s", message);
		exit(exit_code);
	}
}
//Resource temporarily unavailable only happens when there
// is no actual error, like u put error_code == 1 but
// is that an actual error with it?
