/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:08:03 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 05:25:23 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/obx.h"

static void	lil_set_bounding_box(t_obx *obx)
{
	obx->minimap.corners[TOPLEFT] = NULL;
	obx->minimap.corners[TOPRIGHT] = NULL;
	obx->minimap.corners[BOTTLEFT] = NULL;
	obx->minimap.corners[BOTTRIGHT] = NULL;
	if (obx->minimap.box)
	{
		obx->minimap.corners[TOPLEFT] = get_topleft(obx, obx->minimap.center, -1);
		obx->minimap.corners[TOPRIGHT] = get_topright(obx, obx->minimap.center, -1);
		obx->minimap.corners[BOTTLEFT] = get_bottleft(obx, obx->minimap.center, -1);
		obx->minimap.corners[BOTTRIGHT] = get_bottright(obx, obx->minimap.center, -1);
	}
}

static void	lil_set_tiles_ids(t_obx *obx, int i, int j)
{
	while (++i < obx->map.size.y)
	{
		j = -1;
		while (++j < obx->map.size.x)
		{
			if (obx->map.content[i][j] == '0')
				obx->minimap.tiles[i][j].id = '0';
			else if (obx->map.content[i][j] == '1')
				obx->minimap.tiles[i][j].id = '1';
			else if (obx->map.content[i][j] == ' ')
				obx->minimap.tiles[i][j].id = ' ';
			else
			{
				obx->minimap.tiles[i][j].id = 'S';
				obx->minimap.center = &obx->minimap.tiles[i][j];
			}
		}
	}
	lil_set_bounding_box(obx);
}

static	void	lil_set_tiles_colors(t_obx *obx, int i, int j)
{
	while (++i < obx->map.size.y)
	{
		j = -1;
		while (++j < obx->map.size.x)
		{
			obx->minimap.tiles[i][j].crd.x = j;
			obx->minimap.tiles[i][j].crd.y = i;
			if (obx->map.content[i][j] == '1')
				obx->minimap.tiles[i][j].color = 0x0000FF;
			else if (obx->map.content[i][j] == ' ')
				obx->minimap.tiles[i][j].color = 0xFFFFFF;
			else
				obx->minimap.tiles[i][j].color = 0xD3D3D3;
		}
	}
	lil_set_tiles_ids(obx, -1, -1);
}

static void	get_tile_size(t_obx *obx)
{
	int	max;

	if (obx->map.size.x < 11 || obx->map.size.y < 11)
	{
		if (obx->map.size.x > obx->map.size.y)
			max = obx->map.size.x;
		else
			max = obx->map.size.y;
		obx->minimap.tilesize = (int)floor(220 / max);
		obx->minimap.box = 0;
	}
	else
	{
		obx->minimap.tilesize = 20;
		obx->minimap.box = 1;
	}
}

void	init_lilmap(t_obx *obx, int i)
{
	get_tile_size(obx);
	obx->minimap.lil.width = 220;
	obx->minimap.lil.height = 220;
	obx->minimap.lil.img = mlx_new_image(obx->mlx, 220, 220);
	obx->minimap.lil.addr = mlx_get_data_addr(obx->minimap.lil.img, &obx->minimap.lil.bpp, &obx->minimap.lil.line_len, &obx->minimap.lil.endian);
	obx->minimap.tiles = (t_tile **)malloc(sizeof(t_tile *) * (obx->map.size.y));
	while (++i < obx->map.size.y)
	{
		obx->minimap.tiles[i] = (t_tile *)malloc(sizeof(t_tile) * obx->map.size.x);
		obx->minimap.tiles[i]->up = NULL;
		obx->minimap.tiles[i]->down = NULL;
		obx->minimap.tiles[i]->left = NULL;
		obx->minimap.tiles[i]->right = NULL;
		obx->minimap.tiles[i]->upleft = NULL;
		obx->minimap.tiles[i]->upright = NULL;
		obx->minimap.tiles[i]->downleft = NULL;
		obx->minimap.tiles[i]->downright = NULL;
	}
	lil_link_tiles(obx, 0, 0);
	lil_set_tiles_colors(obx, -1, -1);
}