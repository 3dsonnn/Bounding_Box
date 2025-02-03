/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longestr_mtx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:50:11 by efinda            #+#    #+#             */
/*   Updated: 2025/01/11 17:56:05 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_longestr_mtx(char **mtx)
{
	int	i;
	int	res;

	i = -1;
	if (!mtx || !*mtx)
		return (i);
	res = ft_strlen(*mtx);
	while (mtx[++i])
		if (ft_strlen(mtx[i]) > res)
			res = ft_strlen(mtx[i]);
	return (res);
}
