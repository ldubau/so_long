/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:48:24 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/12 18:25:46 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
		count += ft_putnbr(n);
	}
	else
	{
		if (n > 9)
		{
			count += ft_putnbr(n / 10);
			count += ft_putchar(n % 10 + '0');
		}
		else
			count += ft_putchar(n + '0');
	}
	return (count);
}
