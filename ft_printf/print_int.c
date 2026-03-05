/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:47:16 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/12 16:44:47 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(const char format, int value)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += write (1, &value, 1);
	else if (format == 'i' || format == 'd')
		count = ft_putnbr(value);
	return (count);
}
