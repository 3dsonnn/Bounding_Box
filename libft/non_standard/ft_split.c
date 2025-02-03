/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:03:56 by efinda            #+#    #+#             */
/*   Updated: 2024/05/22 00:04:04 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	init_p(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

static char	**ft_fill_matrix(char const *s, char c, int wc)
{
	char	**res;
	int		p[3];

	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	init_p(&p[0], &p[1], &p[2]);
	while (s[p[0]])
	{
		while (s[p[0]] && s[p[0]] == c)
			p[0]++;
		p[1] = p[0];
		while (s[p[0]] && s[p[0]] != c)
			p[0]++;
		if (p[0] > p[1])
		{
			res[p[2]] = (char *)malloc(sizeof(char) * (p[0] - p[1] + 1));
			if (!res[p[2]])
				return (NULL);
			ft_strlcpy(res[p[2]], &s[p[1]], (p[0] - p[1] + 1));
			p[2]++;
		}
	}
	res[p[2]] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_fill_matrix(s, c, ft_word_count(s, c));
	return (res);
}
