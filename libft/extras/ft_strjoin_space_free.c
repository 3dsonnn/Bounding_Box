/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_space_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:54:16 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 06:55:04 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_join_space(char *new_str, char *str, char *buffer)
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
	new_str[i] = ' ';
	i++;
	while (buffer && buffer[j])
	{
		new_str[i + j] = buffer[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	*ft_strjoin_space_free(char *str, char *buffer)
{
	char	*new_str;
	int		lstr;
	int		lbuffer;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	lstr = ft_strlen(str);
	lbuffer = ft_strlen(buffer);
	new_str = (char *)malloc(sizeof(char) * (lstr + lbuffer + 2));
	if (!new_str)
		return (NULL);
	new_str = ft_join_space(new_str, str, buffer);
	ft_strfree(&str);
	return (new_str);
}
