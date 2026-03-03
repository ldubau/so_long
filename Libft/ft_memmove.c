/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:45:37 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/11 15:03:39 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destc;
	unsigned char	*srcc;
	size_t			i;

	destc = (unsigned char *) dest;
	srcc = (unsigned char *) src;
	i = 0;
	if (destc > srcc)
	{
		while (n -- > 0)
			destc[n] = srcc[n];
	}
	else
	{
		while (i < n)
		{
			i ++;
			destc[i - 1] = srcc[i - 1];
		}
	}
	return (dest);
}
