/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:45:37 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/12 18:14:27 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(const char format, unsigned int value)
{
	int	count;

	count = 0;
	if (format == 'x')
		count += putnbr_base(value, "0123456789abcdef");
	else
		count += putnbr_base(value, "0123456789ABCDEF");
	return (count);
}
