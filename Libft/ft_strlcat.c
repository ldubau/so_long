/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:52:42 by ldubau            #+#    #+#             */
/*   Updated: 2025/10/23 16:11:25 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i ++;
	if (i < size)
	{
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i ++;
			j ++;
		}
		dst[i] = '\0';
	}
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}
