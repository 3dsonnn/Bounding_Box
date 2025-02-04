/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:11:00 by efinda            #+#    #+#             */
/*   Updated: 2025/02/03 14:07:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void    exit_map(char *message, t_map *map)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    ft_strfree(&map->line);
    free_rows(&map->head);
    ft_mtxfree(&map->content);
    exit(1);  
}

static void	check_args(t_map *map, int ac, char **av)
{
	if (ac != 2)
		exit_map("Invalid number of arguments", map);
	if (ft_strlen(av[1]) <= 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".obx", 4))
		exit_map("Invalid map file extension", map);
	map->fd = open(av[1], O_RDONLY);
	if (map->fd < 0)
		exit_map(strerror(errno), map);
}

static void	check_map(t_map *map)
{
	map->line = get_next_line(map->fd);
	if (!map->line)
		exit_map("Empty map file", map);
    if (map->line[ft_strlen(map->line) - 1] == '\n')
	    map->line[ft_strlen(map->line) - 1] = '\0';
    else
        exit_map("Invalid map file: it cannot contain only one line", map);
	if (!*map->line || ft_strspace(map->line))
		exit_map("Invalid map file: it cannot start with an empty line", map);
	if (ft_strspn(map->line, "01 S") != ft_strlen(map->line))
		exit_map("Invalid character inside the map", map);
	add_row(&map->head, new_row(map->line));
	ft_strfree(&map->line);
	fill_map(map);
    //check_map_size(map);
	check_starting_position(map);
	is_surrounded(map);
}

void	checks(t_map *map, int ac, char **av)
{
	map->line = NULL;
	map->head = NULL;
	map->content = NULL;
	check_args(map, ac, av);
	check_map(map);
}