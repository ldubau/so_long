/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:50:24 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/12 18:10:19 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c' || format == 'i' || format == 'd')
		count += print_int(format, va_arg(args, int));
	if (format == 's')
		count += print_str(va_arg(args, char *));
	if (format == 'p')
		count += print_void(va_arg(args, void *));
	if (format == 'x' || format == 'X')
		count += print_hexa(format, va_arg(args, unsigned int));
	if (format == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	if (format == '%')
		count += write (1, "%", 1);
	format ++;
	return (count);
}
