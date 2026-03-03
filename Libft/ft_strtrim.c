/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:28:21 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/11 14:44:56 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_value(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	start;
	size_t			end;
	char			*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (find_value(set, s1[start]))
		start ++;
	while (find_value(set, s1[end - 1]))
		end --;
	if (start >= end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start);
	return (str);
}
