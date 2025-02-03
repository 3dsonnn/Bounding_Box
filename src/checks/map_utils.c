/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:27:48 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 17:49:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/TBR.h"

static void	check_empty_spaces(t_map *map)
{
	int	p[3];

	ft_memset(p, -1, 3 * sizeof(int));
	if (ft_strchr(*map->content, '0') || ft_strchr(map->content[map->size.y
			- 1], '0'))
		exit_map("Map not surrounded by walls", map);
	while (++(*p) < map->size.y)
		if (*map->content[*p] == '0' || map->content[*p][map->size.x
			- 1] == '0')
			exit_map("Map not surrounded by walls", map);
	while (++(p[1]) < map->size.y)
	{
		p[2] = -1;
		while (++(p[2]) < map->size.x)
			if (map->content[p[1]][p[2]] == '0')
				if (map->content[p[1] + 1][p[2]] == ' ' || map->content[p[1]
					- 1][p[2]] == ' ' || map->content[p[1]][p[2] + 1] == ' '
					|| map->content[p[1]][p[2] - 1] == ' ' || map->content[p[1]
					- 1][p[2] - 1] == ' ' || map->content[p[1] - 1][p[2]
					+ 1] == ' ' || map->content[p[1] + 1][p[2] - 1] == ' '
					|| map->content[p[1] + 1][p[2] + 1] == ' ')
					exit_map("A 0 cannot be surrounded by a space", map);
	}
}

static void	check_start_pos(t_map *map)
{
	int	p[3];

	ft_memset(p, -1, 3 * sizeof(int));
	if (ft_strchr(*map->content, map->content[map->postart.y][map->postart.x])
		|| ft_strchr(map->content[map->size.y - 1],
			map->content[map->postart.y][map->postart.x]))
		exit_map("Map not surrounded by walls", map);
	while (++(*p) < map->size.y)
		if (*map->content[*p] == map->content[map->postart.y][map->postart.x]
			|| map->content[*p][map->size.x
			- 1] == map->content[map->postart.y][map->postart.x])
			exit_map("Map not surrounded by walls", map);
	while (++(p[1]) < map->size.y)
	{
		p[2] = -1;
		while (++(p[2]) < map->size.x)
			if (map->content[p[1]][p[2]] == map->content[map->postart.y][map->postart.x])
				if (map->content[p[1] + 1][p[2]] == ' ' || map->content[p[1]
					- 1][p[2]] == ' ' || map->content[p[1]][p[2] + 1] == ' '
					|| map->content[p[1]][p[2] - 1] == ' ' || map->content[p[1]
					+ 1][p[2] + 1] == ' ' || map->content[p[1] + 1][p[2]
					- 1] == ' ' || map->content[p[1] - 1][p[2] + 1] == ' '
					|| map->content[p[1] - 1][p[2] - 1] == ' ')
					exit_map("The start position cannot be surrounded by a space",
						map);
	}
}

static void	check_spaces(t_map *map, int x, int y)
{
	while (++y < map->size.y)
	{
		x = -1;
		while (++x < map->size.x)
		{
			if (map->content[y][x] == ' ')
			{
				if ((y > 0 && !ft_strchr(" 1", map->content[y - 1][x]))
					|| (y < map->size.y - 1 && !ft_strchr(" 1", map->content[y
							+ 1][x])) || (x > 0 && !ft_strchr(" 1",
							map->content[y][x - 1])) || (x < map->size.x - 1
						&& !ft_strchr(" 1", map->content[y][x + 1])) || (y > 0
						&& x > 0 && !ft_strchr(" 1", map->content[y - 1][x
							- 1])) || (y > 0 && x < map->size.x - 1
						&& !ft_strchr(" 1", map->content[y - 1][x + 1]))
					|| (y < map->size.y - 1 && x > 0 && !ft_strchr(" 1",
							map->content[y + 1][x - 1])) || (y < map->size.y - 1
						&& x < map->size.x - 1 && !ft_strchr(" 1",
							map->content[y + 1][x + 1])))
					exit_map("A space can only be surrounded by another space or a wall",
						map);
			}
		}
	}
}

void	is_surrounded(t_map *map)
{
	check_empty_spaces(map);
	check_start_pos(map);
	check_spaces(map, -1, -1);
}
