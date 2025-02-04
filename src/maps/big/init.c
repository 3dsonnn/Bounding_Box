/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:59:30 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 04:39:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/obx.h"

static	void	grand_set_tiles_colors(t_obx *obx, int i, int j)
{
	while (++i < obx->map.size.y)
	{
		j = -1;
		while (++j < obx->map.size.x)
		{
			obx->grandmap.tiles[i][j].crd.x = j;
			obx->grandmap.tiles[i][j].crd.y = i;
			if (obx->map.content[i][j] == '0')
			{
				obx->grandmap.tiles[i][j].id = '0';
				obx->grandmap.tiles[i][j].color = 0xD3D3D3;
			}
			else if (obx->map.content[i][j] == '1')
			{
				obx->grandmap.tiles[i][j].id = '1';
				obx->grandmap.tiles[i][j].color = 0x0000FF;
			}
			else if (obx->map.content[i][j] == ' ')
			{
				obx->grandmap.tiles[i][j].id = ' ';
				obx->grandmap.tiles[i][j].color = 0xFFFFFF;
			}
			else
			{
				obx->grandmap.tiles[i][j].id = 'S';
				obx->grandmap.tiles[i][j].color = 0xD3D3D3;
				obx->grandmap.cur = &obx->grandmap.tiles[i][j];
			}
		}
	}
}

void	init_grandmap(t_obx *obx, int i)
{
	int	tmp[2];

	*tmp = (int)floor(WIDTH / obx->map.size.y);
	*(tmp + 1) = (int)floor(HEIGHT / obx->map.size.x);
	if (*tmp > *(tmp + 1))
		obx->grandmap.tilesize = *(tmp + 1);
	else
		obx->grandmap.tilesize = *tmp;
	obx->grandmap.big.width = WIDTH;
	obx->grandmap.big.height = HEIGHT;
    obx->grandmap.big.img = mlx_new_image(obx->mlx, WIDTH, HEIGHT);
	obx->grandmap.big.addr = mlx_get_data_addr(obx->grandmap.big.img, &obx->grandmap.big.bpp, &obx->grandmap.big.line_len, &obx->grandmap.big.endian);
    obx->grandmap.tiles = (t_tile **)malloc(sizeof(t_tile *) * (obx->map.size.y));
	while (++i < obx->map.size.y)
	{
		obx->grandmap.tiles[i] = (t_tile *)malloc(sizeof(t_tile) * obx->map.size.x);
		obx->grandmap.tiles[i]->up = NULL;
		obx->grandmap.tiles[i]->down = NULL;
		obx->grandmap.tiles[i]->left = NULL;
		obx->grandmap.tiles[i]->right = NULL;
		obx->grandmap.tiles[i]->upleft = NULL;
		obx->grandmap.tiles[i]->upright = NULL;
		obx->grandmap.tiles[i]->downleft = NULL;
		obx->grandmap.tiles[i]->downright = NULL;
	}
	grand_link_tiles(obx, 0, 0);
	grand_set_tiles(obx, -1, -1);
}
