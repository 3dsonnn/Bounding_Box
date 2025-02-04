/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:03:10 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 08:24:58 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	set_bounding_box(t_obx *obx)
{
	if (!obx->minimap.box)
    {
        obx->minimap.corners[TOPLEFT] = NULL;
        obx->minimap.corners[TOPRIGHT] = NULL;
        obx->minimap.corners[BOTTLEFT] = NULL;
        obx->minimap.corners[BOTTRIGHT] = NULL;
    }
    else
        update_obx(obx);
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
				obx->tiles[i][j].color = 0x0000FF;
            }
            else if (obx->map.content[i][j] == '0')
            {
                obx->tiles[i][j].id = '0';
				obx->tiles[i][j].color = 0xFFFFFF;
            }
			else if (obx->map.content[i][j] == ' ')
            {
                obx->tiles[i][j].id = ' ';
				obx->tiles[i][j].color = 0xD3D3D3;
            }
			else
            {
                obx->tiles[i][j].id = 'S';
				obx->tiles[i][j].color = 0xFF0000;
                obx->cur = &obx->tiles[i][j];
            }
		}
	}
	set_bounding_box(obx);
}