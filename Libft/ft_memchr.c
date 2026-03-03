/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:59:17 by ldubau            #+#    #+#             */
/*   Updated: 2025/10/24 13:36:47 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	cc;

	i = 0;
	ptr = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (ptr[i] == cc)
			return ((void *)&ptr[i]);
		i ++;
	}
	return (NULL);
}
