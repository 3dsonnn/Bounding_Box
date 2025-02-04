/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_row.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:49:04 by efinda            #+#    #+#             */
/*   Updated: 2025/02/03 13:50:45 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

t_rows	*new_row(char *str)
{
	t_rows	*row;

	row = (t_rows *)malloc(sizeof(t_rows));
	if (!row)
		return (NULL);
	row->str = ft_strdup(str);
	row->next = NULL;
	return (row);
}

void	free_rows(t_rows **head)
{
	t_rows	*tmp;

	if (!head || !*head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_strfree(&tmp->str);
		free(tmp);
	}
	*head = NULL;
}

char	**row_to_mtx(t_rows *head)
{
	char	**mtx;
	t_rows	*tmp;
	int		i;

	if (!head)
		return (NULL);
	mtx = (char **)malloc(sizeof(char *) * (rowlen(head) + 1));
	if (!mtx)
		return (NULL);
	i = 0;
	tmp = head;
	while (tmp)
	{
		mtx[i] = ft_strdup(tmp->str);
		tmp = tmp->next;
		i++;
	}
	mtx[i] = NULL;
	return (mtx);
}
