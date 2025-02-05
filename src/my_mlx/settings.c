/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:03:10 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 18:30:38 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	set_bounding_box(t_obx *obx, t_tile *cur, t_plane plane, t_iter iter)
{
	t_tile	*tmp[4] = {cur, cur, cur, cur};

    while (++(iter.i) < 5 && cur && cur->up)
        tmp[0] = cur = cur->up;
    cur = obx->cur;
    while (++(iter.j) < 5 && cur && cur->down)
        tmp[1] = cur = cur->down;
    cur = obx->cur;
    while (++(iter.k) < 5 && cur && cur->left)
        tmp[2] = cur = cur->left;
    cur = obx->cur;
    while (++(iter.l) < 5 && cur && cur->right)
        tmp[3] = cur = cur->right;
    
    plane.x0 = tmp[2]->crd.x;
    plane.x = tmp[3]->crd.x;
    plane.y0 = tmp[0]->crd.y;
    plane.y = tmp[1]->crd.y;

    obx->minimap.corners[TOPLEFT] = &obx->tiles[plane.y0][plane.x0];
    obx->minimap.corners[TOPRIGHT] = &obx->tiles[plane.y0][plane.x];
    obx->minimap.corners[BOTTLEFT] = &obx->tiles[plane.y][plane.x0];
    obx->minimap.corners[BOTTRIGHT] = &obx->tiles[plane.y][plane.x];
}

void	set_tiles(t_obx *obx, int i, int j)
{
	while (++i < obx->map.size.y)
	{
		j = -1;
		while (++j < obx->map.size.x)
		{
			obx->tiles[i][j].crd.x = j;
			obx->tiles[i][j].crd.y = i;
			if (obx->map.content[i][j] == '1')
			{
				obx->tiles[i][j].id = '1';
				obx->tiles[i][j].color = BLUE;
			}
			else if (obx->map.content[i][j] == '0')
			{
				obx->tiles[i][j].id = '0';
				obx->tiles[i][j].color = WHITE;
			}
			else if (obx->map.content[i][j] == ' ')
			{
				obx->tiles[i][j].id = ' ';
				obx->tiles[i][j].color = 0xD3D3D3;
			}
			else
			{
				obx->tiles[i][j].id = 'S';
				obx->tiles[i][j].color = RED;
				obx->cur = &obx->tiles[i][j];
			}
		}
	}
	if (obx->minimap.box)
		set_bounding_box(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1, -1, -1, -1});
}