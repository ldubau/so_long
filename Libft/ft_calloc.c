/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:32:51 by ldubau            #+#    #+#             */
/*   Updated: 2025/11/11 14:39:15 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (count * size > (size_t) -1)
		return (NULL);
	ptr = malloc(count * size);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < count * size)
		ptr[i ++] = '\0';
	return (ptr);
}
