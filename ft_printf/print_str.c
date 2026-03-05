/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:24:32 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/12 16:47:40 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *value)
{
	int	count;

	count = 0;
	if (value == 0)
	{
		count += write (1, "(null)", 6);
		return (count);
	}
	while (*value)
	{
		write (1, value, 1);
		value ++;
		count ++;
	}
	return (count);
}
