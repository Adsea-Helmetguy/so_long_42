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

#include "../includes/so_long.h"

void	print_message(char *message, int exit_code)
{
	if (exit_code != 0)
	{
		ft_printf("Error\n");
		perror(message);
		exit(exit_code);
	}
	else
	{
		ft_printf("%s", message);
		exit(exit_code);
	}
}
