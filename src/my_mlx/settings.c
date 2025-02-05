/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:03:10 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 22:24:12 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

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
		update_obx(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1, -1, -1, -1});
}