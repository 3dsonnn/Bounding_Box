/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:48:26 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 04:49:23 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/obx.h"

static void	lil_link_diagonals(t_obx *obx, int i, int j)
{
	while (++i < obx->scene.map.size.y - 1)
	{
		obx->grandmap.tiles[i][0].upright = &obx->grandmap.tiles[i - 1][1];
		obx->grandmap.tiles[i][0].downright = &obx->grandmap.tiles[i + 1][1];
		obx->grandmap.tiles[i][obx->scene.map.size.x
			- 1].upleft = &obx->grandmap.tiles[i - 1][obx->scene.map.size.x - 2];
		obx->grandmap.tiles[i][obx->scene.map.size.x
			- 1].downleft = &obx->grandmap.tiles[i + 1][obx->scene.map.size.x
			- 2];
	}
	while (++j < obx->scene.map.size.x - 1)
	{
		obx->grandmap.tiles[0][j].downleft = &obx->grandmap.tiles[1][j - 1];
		obx->grandmap.tiles[0][j].downright = &obx->grandmap.tiles[1][j + 1];
		obx->grandmap.tiles[obx->scene.map.size.y
			- 1][j].upleft = &obx->grandmap.tiles[obx->scene.map.size.y - 2][j
			- 1];
		obx->grandmap.tiles[obx->scene.map.size.y
			- 1][j].upright = &obx->grandmap.tiles[obx->scene.map.size.y - 2][j
			+ 1];
	}
}

static void	lil_link_horizontal_boundary_tiles(t_obx *obx, int i, int j)
{
	while (++j < obx->scene.map.size.x)
	{
		obx->grandmap.tiles[0][j].down = &obx->grandmap.tiles[1][j];
		obx->grandmap.tiles[obx->scene.map.size.y
			- 1][j].up = &obx->grandmap.tiles[obx->scene.map.size.y - 2][j];
		if (j != 0)
		{
			obx->grandmap.tiles[0][j].left = &obx->grandmap.tiles[0][j - 1];
			obx->grandmap.tiles[obx->scene.map.size.y
				- 1][j].left = &obx->grandmap.tiles[obx->scene.map.size.y - 1][j
				- 1];
		}
		if (j != obx->scene.map.size.x - 1)
		{
			obx->grandmap.tiles[0][j].right = &obx->grandmap.tiles[0][j + 1];
			obx->grandmap.tiles[obx->scene.map.size.y
				- 1][j].right = &obx->grandmap.tiles[obx->scene.map.size.y - 1][j
				+ 1];
		}
	}
	lil_link_diagonals(obx, 0, 0);
}

static void	lil_link_vertical_boundary_tiles(t_obx *obx, int i, int j)
{
	while (++i < obx->scene.map.size.y)
	{
		obx->grandmap.tiles[i][0].right = &obx->grandmap.tiles[i][1];
		obx->grandmap.tiles[i][obx->scene.map.size.x
			- 1].left = &obx->grandmap.tiles[i][obx->scene.map.size.x - 2];
		if (i != 0)
		{
			obx->grandmap.tiles[i][0].up = &obx->grandmap.tiles[i - 1][0];
			obx->grandmap.tiles[i][obx->scene.map.size.x
				- 1].up = &obx->grandmap.tiles[i - 1][obx->scene.map.size.x - 1];
		}
		if (i != obx->scene.map.size.y - 1)
		{
			obx->grandmap.tiles[i][0].down = &obx->grandmap.tiles[i + 1][0];
			obx->grandmap.tiles[i][obx->scene.map.size.x
				- 1].down = &obx->grandmap.tiles[i + 1][obx->scene.map.size.x
				- 1];
		}
	}
	lil_link_horizontal_boundary_tiles(obx, -1, -1);
}

static	void	lil_link_corners(t_obx *obx)
{
	obx->grandmap.tiles[0][0].downright = &obx->grandmap.tiles[1][1];
	obx->grandmap.tiles[obx->scene.map.size.y
		- 1][0].upright = &obx->grandmap.tiles[obx->scene.map.size.y - 2][1];
	obx->grandmap.tiles[0][obx->scene.map.size.x
		- 1].downleft = &obx->grandmap.tiles[1][obx->scene.map.size.x - 2];
	obx->grandmap.tiles[obx->scene.map.size.y - 1][obx->scene.map.size.x
		- 1].upleft = &obx->grandmap.tiles[obx->scene.map.size.y
		- 2][obx->scene.map.size.x - 2];
}

void	lil_link_tiles(t_obx *obx, int i, int j)
{
	lil_link_corners(obx);
	lil_link_vertical_boundary_tiles(obx, -1, -1);
	while (++i < obx->scene.map.size.y - 1)
	{
		j = 0;
		while (++j < obx->scene.map.size.x - 1)
		{
			obx->grandmap.tiles[i][j].up = &obx->grandmap.tiles[i - 1][j];
			obx->grandmap.tiles[i][j].down = &obx->grandmap.tiles[i + 1][j];
			obx->grandmap.tiles[i][j].left = &obx->grandmap.tiles[i][j - 1];
			obx->grandmap.tiles[i][j].right = &obx->grandmap.tiles[i][j + 1];
			obx->grandmap.tiles[i][j].upleft = &obx->grandmap.tiles[i - 1][j - 1];
			obx->grandmap.tiles[i][j].upright = &obx->grandmap.tiles[i - 1][j
				+ 1];
			obx->grandmap.tiles[i][j].downleft = &obx->grandmap.tiles[i + 1][j
				- 1];
			obx->grandmap.tiles[i][j].downright = &obx->grandmap.tiles[i + 1][j
				+ 1];
		}
	}
}
