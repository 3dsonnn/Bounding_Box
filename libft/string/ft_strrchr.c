/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:59:33 by efinda            #+#    #+#             */
/*   Updated: 2024/05/22 00:59:39 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (last == -1)
		return (NULL);
	return ((char *)&s[last]);
}
