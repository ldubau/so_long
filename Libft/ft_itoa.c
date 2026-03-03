/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:39:21 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/11 15:18:48 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i ++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		i ++;
	}
	i ++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = len_nbr(nbr);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	str[len] = '\0';
	while (len > 0 && str[len - 1] != '-')
	{
		len --;
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
