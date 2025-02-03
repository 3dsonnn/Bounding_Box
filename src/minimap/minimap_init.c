/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 02:08:03 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 18:01:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/TBR.h"

static void	set_tiles_ids(t_cub *cub, int i, int j)
{
	while (++i < cub->scene.map.size.y)
	{
		j = -1;
		while (++j < cub->scene.map.size.x)
		{
			if (cub->scene.map.content[i][j] == '0')
				cub->minimap.tiles[i][j].id = '\0';
			else if (cub->scene.map.content[i][j] == '1')
				cub->minimap.tiles[i][j].id = '1';
			else if (cub->scene.map.content[i][j] == ' ')
				cub->minimap.tiles[i][j].id = ' ';
			else
				cub->minimap.tiles[i][j].id = cub->scene.map.start;
		}
	}
}

void	set_tiles_colors(t_cub *cub, int i, int j)
{
	while (++i < cub->scene.map.size.y)
	{
		j = -1;
		while (++j < cub->scene.map.size.x)
		{
			if (cub->scene.map.content[i][j] == '1')
				cub->minimap.tiles[i][j].color = 0x0000FF;
			else if (cub->scene.map.content[i][j] == ' ')
				cub->minimap.tiles[i][j].color = 0xFFFFFF;
			else
				cub->minimap.tiles[i][j].color = 0xD3D3D3;
		}
	}
	set_tiles_ids(cub, -1, -1);
}

void	init_minimap(t_cub *cub, int i, int j)
{
	cub->minimap.tilewidth = (int)floor(MINIWIDTH / cub->scene.map.size.x);
	cub->minimap.tileheight = (int)floor(MINIHEIGHT / cub->scene.map.size.y);
	cub->minimap.miniwidth = cub->minimap.tilewidth * cub->scene.map.size.x;
	cub->minimap.miniheight = cub->minimap.tileheight * cub->scene.map.size.y;
	cub->minimap.img.img = mlx_new_image(cub->mlx, cub->minimap.miniwidth,
			cub->minimap.miniheight);
	cub->minimap.img.addr = mlx_get_data_addr(cub->minimap.img.img,
			&cub->minimap.img.bpp, &cub->minimap.img.line_len,
			&cub->minimap.img.endian);
	cub->minimap.tiles = (t_tile **)malloc(sizeof(t_tile *)
			* (cub->scene.map.size.y));
	while (++i < cub->scene.map.size.y)
	{
		cub->minimap.tiles[i] = (t_tile *)malloc(sizeof(t_tile)
				* cub->scene.map.size.x);
		cub->minimap.tiles[i]->up = NULL;
		cub->minimap.tiles[i]->down = NULL;
		cub->minimap.tiles[i]->left = NULL;
		cub->minimap.tiles[i]->right = NULL;
		cub->minimap.tiles[i]->upleft = NULL;
		cub->minimap.tiles[i]->upright = NULL;
		cub->minimap.tiles[i]->downleft = NULL;
		cub->minimap.tiles[i]->downright = NULL;
	}
	link_tiles(cub, 0, 0);
}
