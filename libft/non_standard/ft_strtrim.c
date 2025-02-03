/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:59:55 by efinda            #+#    #+#             */
/*   Updated: 2024/05/22 00:59:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!str || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(str);
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	while (str[j - 1] && ft_strchr(set, str[j - 1]) && j > i)
		j--;
	res = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &str[i], j - i + 1);
	return (res);
}
