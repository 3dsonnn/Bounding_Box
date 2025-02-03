/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init_tiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 05:58:16 by efinda            #+#    #+#             */
/*   Updated: 2025/01/21 16:16:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	init_horizontal_boundary_tiles_x(t_cub *cub, int j)
{
	cub->minimap.tiles[0][0].pos.x0 = 0;
	cub->minimap.tiles[0][0].pos.x = cub->minimap.tilewidth;
	cub->minimap.tiles[0][cub->scene.map.size.x
		- 1].pos.x0 = cub->minimap.miniwidth - cub->minimap.tilewidth;
	cub->minimap.tiles[0][cub->scene.map.size.x
		- 1].pos.x = cub->minimap.miniwidth;
	while (++j < cub->scene.map.size.x - 1)
	{
		cub->minimap.tiles[0][j].pos.x0 = cub->minimap.tiles[0][j].left->pos.x;
		cub->minimap.tiles[0][j].pos.x = cub->minimap.tiles[0][j].pos.x0
			+ cub->minimap.tilewidth;
		cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].pos.x0 = cub->minimap.tiles[0][j].left->pos.x;
		cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].pos.x = cub->minimap.tiles[0][j].pos.x0
			+ cub->minimap.tilewidth;
	}
}

static void	init_horizontal_boundary_tiles_y(t_cub *cub, int j)
{
	while (++j < cub->scene.map.size.x)
	{
		cub->minimap.tiles[0][j].pos.y0 = 0;
		cub->minimap.tiles[0][j].pos.y = cub->minimap.tileheight;
		cub->minimap.tiles[0][j].down->pos.y0 = cub->minimap.tiles[0][j].pos.y;
		cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].pos.y0 = cub->minimap.miniheight - cub->minimap.tileheight;
		cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].pos.y = cub->minimap.miniheight;
		cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].up->pos.y = cub->minimap.tiles[cub->scene.map.size.y
			- 1][j].pos.y0;
	}
	init_horizontal_boundary_tiles_x(cub, 0);
}

static void	init_vertical_boundary_tiles_y(t_cub *cub, int i)
{
	cub->minimap.tiles[0][0].pos.y0 = 0;
	cub->minimap.tiles[0][0].pos.y = cub->minimap.tileheight;
	cub->minimap.tiles[0][cub->scene.map.size.x - 1].pos.y0 = 0;
	cub->minimap.tiles[0][cub->scene.map.size.x
		- 1].pos.y = cub->minimap.tileheight;
	while (++i < cub->scene.map.size.y)
	{
		cub->minimap.tiles[i][0].pos.y0 = cub->minimap.tiles[i][0].up->pos.y;
		cub->minimap.tiles[i][0].pos.y = cub->minimap.tiles[i][0].pos.y0
			+ cub->minimap.tileheight;
		cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].pos.y0 = cub->minimap.tiles[i][0].up->pos.y;
		cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].pos.y = cub->minimap.tiles[i][0].pos.y0
			+ cub->minimap.tileheight;
	}
	init_horizontal_boundary_tiles_y(cub, -1);
}

static void	init_vertical_boundary_tiles_x(t_cub *cub, int i)
{
	while (++i < cub->scene.map.size.y)
	{
		cub->minimap.tiles[i][0].pos.x0 = 0;
		cub->minimap.tiles[i][0].pos.x = cub->minimap.tilewidth;
		cub->minimap.tiles[i][0].right->pos.x0 = cub->minimap.tiles[i][0].pos.x;
		cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].pos.x0 = cub->minimap.miniwidth - cub->minimap.tilewidth;
		cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].pos.x = cub->minimap.miniwidth;
		cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].left->pos.x = cub->minimap.tiles[i][cub->scene.map.size.x
			- 1].pos.x0;
	}
	init_vertical_boundary_tiles_y(cub, 0);
}

void	init_tiles(t_cub *cub, int i, int j)
{
	init_vertical_boundary_tiles_x(cub, -1);
	while (++i < cub->scene.map.size.y - 1)
	{
		j = 0;
		while (++j < cub->scene.map.size.x - 1)
		{
			cub->minimap.tiles[i][j].pos.x0 = cub->minimap.tiles[i][j].left->pos.x;
			cub->minimap.tiles[i][j].pos.x = cub->minimap.tiles[i][j].pos.x0
				+ cub->minimap.tilewidth;
			cub->minimap.tiles[i][j].right->pos.x0 = cub->minimap.tiles[i][j].pos.x;
			cub->minimap.tiles[i][j].pos.y0 = cub->minimap.tiles[i][j].up->pos.y;
			cub->minimap.tiles[i][j].pos.y = cub->minimap.tiles[i][j].pos.y0
				+ cub->minimap.tileheight;
			cub->minimap.tiles[i][j].down->pos.y0 = cub->minimap.tiles[i][j].pos.y;
		}
	}
	set_tiles_colors(cub, -1, -1);
}
