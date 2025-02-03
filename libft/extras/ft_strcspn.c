/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:42:31 by efinda            #+#    #+#             */
/*   Updated: 2024/11/14 06:42:32 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcspn(char *s, char *reject)
{
	int	i;
	int	j;

	i = -1;
	if (!s || !reject)
		return (-1);
	while (s[++i])
	{
		j = -1;
		while (reject[++j])
			if (s[i] == reject[j])
				return (i);
	}
	return (i);
}
