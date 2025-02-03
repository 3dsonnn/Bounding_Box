/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 08:03:21 by efinda            #+#    #+#             */
/*   Updated: 2025/01/12 10:35:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_free(char *str, char *buffer)
{
	char	*new_str;

	if (!str && !buffer)
		return (NULL);
	if (!str)
		return (ft_strdup(buffer));
	if (!buffer)
		return (str);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer)
				+ 1));
	if (!new_str)
		return (NULL);
	new_str = ft_join(new_str, str, buffer);
	ft_strfree(&str);
	return (new_str);
}
