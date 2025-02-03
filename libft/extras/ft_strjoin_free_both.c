/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_both.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:56:50 by efinda            #+#    #+#             */
/*   Updated: 2024/11/30 14:56:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_free_both(char *str, char *buffer)
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
	new_str = (char *)malloc(sizeof(char) * (lstr + lbuffer + 1));
	if (!new_str)
		return (NULL);
	new_str = ft_join(new_str, str, buffer);
	ft_strfree(&str);
	ft_strfree(&buffer);
	return (new_str);
}
