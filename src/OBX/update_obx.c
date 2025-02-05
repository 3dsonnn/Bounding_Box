/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_obx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:24:23 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 22:09:11 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void    update_obx(t_obx *obx, t_tile *cur, t_plane plane, t_iter iter)
{
    if (!obx->minimap.box)
        return ;
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

    obx->minimap.refs[REF] = &obx->tiles[plane.y0][plane.x0];
    obx->minimap.refs[REF_X] = &obx->tiles[plane.y0][plane.x];
    obx->minimap.refs[REF_Y] = &obx->tiles[plane.y][plane.x0];

    if (!obx->minimap.refs[REF_X]->right)
        obx->minimap.refs[REF] = &obx->tiles[plane.y0][plane.x - 10];

    if (!obx->minimap.refs[REF_Y]->down)
	{
		obx->minimap.refs[REF] = &obx->tiles[plane.y - 10][plane.x0];
	}
}
