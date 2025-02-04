/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 02:23:44 by efinda            #+#    #+#             */
/*   Updated: 2025/02/03 14:06:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	fill_map_aux(t_map *map)
{
	int	i;
	int	len;

	i = -1;
	while (++i < map->size.y)
	{
		len = ft_strlen(map->content[i]);
		if (len < map->size.x)
		{
			map->line = ft_calloc(map->size.x + 1, sizeof(char));
			ft_strnfill(map->line, map->content[i], len);
			ft_memset(map->line + len, ' ', map->size.x - len);
			ft_strfree(&map->content[i]);
			map->content[i] = map->line;
			map->line = NULL;
		}
	}
}

void	fill_map(t_map *map)
{
	while (-42)
	{
		map->line = get_next_line(map->fd);
		if (!map->line)
			break ;
		if (map->line[ft_strlen(map->line) - 1] == '\n')
			map->line[ft_strlen(map->line) - 1] = '\0';
		if (!*map->line || ft_strspace(map->line))
			exit_map("There cannot be empty lines inside the map content", map);
		if (ft_strspn(map->line, "01 S") != ft_strlen(map->line))
			exit_map("Invalid character inside the map", map);
		add_row(&map->head, new_row(map->line));
		ft_strfree(&map->line);
	}
	map->content = row_to_mtx(map->head);
	free_rows(&map->head);
	map->size.x = ft_longestr_mtx(map->content);
	map->size.y = ft_mtxlen(map->content);
	fill_map_aux(map);
}

void	check_starting_position(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < map->size.y)
	{
		j = -1;
		while (++j < map->size.x)
		{
			if (ft_strchr("S", map->content[i][j]))
			{
				map->start.x = j;
				map->start.y = i;
				flag++;
			}
		}
	}
	if (!flag)
		exit_map("There isn't a start position on the map", map);
	if (flag > 1)
		exit_map("There's more than one start position on the map", map);
}
