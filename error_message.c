/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:51:02 by ldubau            #+#    #+#             */
/*   Updated: 2026/03/05 13:29:56 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (0);
}
