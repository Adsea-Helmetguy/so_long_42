/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:43:51 by mlow              #+#    #+#             */
/*   Updated: 2023/12/03 19:44:02 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../other_srcs/libft_project/libft.h"
#include "../other_srcs/printf_project/libftprintf.h"
#include "../other_srcs/get_next_line_project/get_next_line.h"
#include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/so_long.h"

/*
  Since each byte contains 2^8 = 256 values (1 byte = 8 bits),
  and RGB values range from 0 to 255, 
  we can perfectly fit a unsigned char for each TRGB parameters 
  {T, R, G, B} (char is 1 byte)
  and fit a int for the TRGB value (int is 4 bytes).
*/
int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
//Creating a trGB value for the color red   
//  int red_trgb = create_trgb(255, 255, 0, 0);

/*
    Extracting individual components
    unsigned char red_t = get_t(red_trgb);
    unsigned char red_r = get_r(red_trgb);
    unsigned char red_g = get_g(red_trgb);
    unsigned char red_b = get_b(red_trgb);
*/
unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
