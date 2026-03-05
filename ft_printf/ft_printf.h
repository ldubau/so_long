/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:34:46 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/12 18:30:57 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		check_format(char format, va_list args);
int		print_int(const char format, int value);
int		print_hexa(const char format, unsigned int value);
int		print_str(char *value);
int		print_unsigned(unsigned int n);
int		print_void(void *p);
int		putnbr_base(unsigned long nbr, char *base);
int		ft_putnbr(long n);
int		ft_putchar(int c);

#endif
