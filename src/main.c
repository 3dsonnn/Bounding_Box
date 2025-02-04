/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:58:45 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 09:33:44 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/obx.h"

static void	print_map(t_map map)
{
	int	i;

	i = -1;
	printf("\n");
	while (++i < map.size.y)
		printf("%s\n", map.content[i]);
	printf("\n");
}

int	main(int ac, char **av)
{
	t_obx	obx;

	(void)av;
	checks(&obx.map, ac, av);
	print_map(obx.map);
	my_mlx_init(&obx);
	my_mlx_hook(&obx);
	bounding_box(&obx, -1, -1);
	mlx_loop(obx.mlx);
	return (0);
}
