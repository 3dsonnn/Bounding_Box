/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_countstr_mtx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:33:06 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 06:35:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_countstr_mtx(char **matrix, char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (!matrix || !(*matrix) || !str)
		return (0);
	while (matrix[++i])
		if (ft_samestr(matrix[i], str))
			res++;
	return (res);
}
