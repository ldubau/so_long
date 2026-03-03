/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:21:09 by ldubau            #+#    #+#             */
/*   Updated: 2025/10/23 16:11:41 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*res;

	i = 0;
	cc = (char) c;
	res = NULL;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i ++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return ((char *) res);
}
