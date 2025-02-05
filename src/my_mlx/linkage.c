/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:36:23 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 21:55:36 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	link_horizontal_boundary_tiles(t_obx *obx, int i, int j)
{
	while (++j < obx->map.size.x)
	{
		obx->tiles[0][j].down = &obx->tiles[1][j];
		obx->tiles[obx->map.size.y - 1][j].up = &obx->tiles[obx->map.size.y - 2][j];
		if (j != 0)
		{
			obx->tiles[0][j].left = &obx->tiles[0][j - 1];
			obx->tiles[obx->map.size.y - 1][j].left = &obx->tiles[obx->map.size.y - 1][j - 1];
		}
		if (j != obx->map.size.x - 1)
		{
			obx->tiles[0][j].right = &obx->tiles[0][j + 1];
			obx->tiles[obx->map.size.y - 1][j].right = &obx->tiles[obx->map.size.y - 1][j + 1];
		}
	}
}

static void	link_vertical_boundary_tiles(t_obx *obx, int i, int j)
{
	while (++i < obx->map.size.y)
	{
		obx->tiles[i][0].right = &obx->tiles[i][1];
		obx->tiles[i][obx->map.size.x - 1].left = &obx->tiles[i][obx->map.size.x - 2];
		if (i != 0)
		{
			obx->tiles[i][0].up = &obx->tiles[i - 1][0];
			obx->tiles[i][obx->map.size.x - 1].up = &obx->tiles[i - 1][obx->map.size.x - 1];
		}
		if (i != obx->map.size.y - 1)
		{
			obx->tiles[i][0].down = &obx->tiles[i + 1][0];
			obx->tiles[i][obx->map.size.x - 1].down = &obx->tiles[i + 1][obx->map.size.x - 1];
		}
	}
	link_horizontal_boundary_tiles(obx, -1, -1);
}

void	link_tiles(t_obx *obx, int i, int j)
{
	link_vertical_boundary_tiles(obx, -1, -1);
	while (++i < obx->map.size.y - 1)
	{
		j = 0;
		while (++j < obx->map.size.x - 1)
		{
			obx->tiles[i][j].up = &obx->tiles[i - 1][j];
			obx->tiles[i][j].down = &obx->tiles[i + 1][j];
			obx->tiles[i][j].left = &obx->tiles[i][j - 1];
			obx->tiles[i][j].right = &obx->tiles[i][j + 1];
		}
	}
}
