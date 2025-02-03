/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 05:59:59 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 06:01:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (++i < n)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}
