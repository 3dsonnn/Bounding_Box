/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:41:31 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 18:42:05 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_join(char *new_str, char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
