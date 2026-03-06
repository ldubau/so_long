/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:51:02 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/06 12:22:29 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_message(int nbr)
{
	if (nbr == 10)
		ft_printf("Error : failed to load wall texture\n");
	else if (nbr == 11)
		ft_printf("Error : failed to load floor texture\n");
	else if (nbr == 12)
		ft_printf("Error : failed to load collect texture\n");
	else if (nbr == 13)
		ft_printf("Error : failed to load exit texture\n");
	else if (nbr == 14)
		ft_printf("Error : failed to load closed exit texture\n");
	else if (nbr == 15)
		ft_printf("Error : failed to load player texture\n");
	else if (nbr == 16)
		ft_printf("Error : wrong texture size\n");
}

int	error_message(int nbr)
{
	if (nbr == 1)
		ft_printf("Error : wrong number of arguments\n");
	else if (nbr == 2)
		ft_printf("Error : not a .ber file\n");
	else if (nbr == 3)
		ft_printf("Error : file doesn't exist\n");
	else if (nbr == 4)
		ft_printf("Error : not a square map\n");
	else if (nbr == 5)
		ft_printf("Error : the walls arren't closed\n");
	else if (nbr == 6)
		ft_printf("Error : missing object (P, C, E, P)\n");
	else if (nbr == 7)
		ft_printf("Error : the game can't be finished\n");
	else if (nbr == 8)
		ft_printf("Error : init failed\n");
	else if (nbr == 9)
		ft_printf("Error : window creation failed\n");
	else if (nbr > 9)
		texture_message(nbr);
	return (0);
}
