/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:22:08 by leondubau         #+#    #+#             */
/*   Updated: 2025/11/11 15:25:44 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	x;
	int	i;
	int	wrd;

	x = 0;
	i = 0;
	wrd = 0;
	while (s[i])
	{
		if (s[i] != c && x == 0)
		{
			x = 1;
			wrd ++;
		}
		else if (s[i] == c)
			x = 0;
		i ++;
	}
	return (wrd);
}

static void	*free_all(char **tbl, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free (tbl[i]);
		i ++;
	}
	free (tbl);
	return (NULL);
}

static char	**tab_build(const char *s, char c, int *i, int *j)
{
	char	**tbl;

	if (!s)
		return (NULL);
	tbl = ft_calloc(sizeof(char *), count_word(s, c) + 1);
	if (!tbl)
		return (NULL);
	*i = 0;
	*j = 0;
	return (tbl);
}

char	**ft_split(char const *s, char c)
{
	char	**tbl;
	int		i;
	int		j;
	int		k;

	tbl = tab_build(s, c, &i, &j);
	if (!tbl)
		return (NULL);
	while (s[i])
	{
		k = 0;
		if (s[i] != c)
		{
			while (s[i + k] && s[i + k] != c)
				k ++;
			tbl[j] = ft_substr(s, i, k);
			if (!tbl[j])
				return (free_all(tbl, j));
			i += k - 1;
			j ++;
		}
		i ++;
	}
	return (tbl);
}
