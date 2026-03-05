/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:08:49 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/12 18:07:00 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	len_base;
	int				count;

	len_base = 0;
	count = 0;
	while (base[len_base])
		len_base ++;
	if (nbr > len_base - 1)
	{
		count += putnbr_base(nbr / len_base, base);
		count += ft_putchar(base[nbr % len_base]);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}
