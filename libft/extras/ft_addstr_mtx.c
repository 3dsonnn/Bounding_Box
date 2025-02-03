/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxexpand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:07:18 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 01:09:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_addstr_mtx(char ***matrix, char **tmp, char *str)
{
	int	i;
	int	tmp_len;

	if (!matrix || !tmp || !(*tmp) || !str)
		return (NULL);
	i = -1;
	tmp_len = ft_mtxlen(tmp);
	*matrix = (char **)malloc(sizeof(char *) * (tmp_len + 2));
	if (!(*matrix))
		return (NULL);
	while (++i < tmp_len)
	{
		(*matrix)[i] = ft_strdup(tmp[i]);
		if (!(*matrix)[i])
		{
			ft_mtxfree(matrix);
			ft_mtxfree(&tmp);
			return (NULL);
		}
	}
	(*matrix)[i] = ft_strdup(str);
	(*matrix)[i + 1] = NULL;
	ft_mtxfree(&tmp);
	return (*matrix);
}
