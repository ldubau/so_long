/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:29:58 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/19 13:19:25 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += check_format(*(format + 1), args);
			format ++;
		}
		else
			count += write (1, format, 1);
		format ++;
	}
	va_end (args);
	return (count);
}
