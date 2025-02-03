/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmtx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:12:11 by efinda            #+#    #+#             */
/*   Updated: 2024/11/10 16:18:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_lstmtx(t_list *lst)
{
	char	**res;
	int		i;

	if (!lst)
		return (NULL);
	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!res)
		return (NULL);
	while (lst)
	{
		res[i] = ft_strdup((char *)lst->content);
		if (!res[i])
		{
			ft_mtxfree(&res);
			return (NULL);
		}
		lst = lst->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
