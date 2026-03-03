/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:17:38 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/05 10:54:20 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destc;
	unsigned char	*srcc;
	size_t			i;

	destc = (unsigned char *) dest;
	srcc = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		destc[i] = srcc[i];
		i ++;
	}
	return (dest);
}
