/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:38:47 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/12 18:27:02 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_void(void *p)
{
	int				count;
	unsigned long	res;

	res = (unsigned long)p;
	if (p == 0)
	{
		count = write (1, "(nil)", 5);
		return (count);
	}
	count = write (1, "0x", 2);
	count += putnbr_base(res, "0123456789abcdef");
	return (count);
}
