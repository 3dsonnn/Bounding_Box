/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:03:00 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 05:27:34 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	move_player_up(t_obx *obx, int i, int j)
{
	if (obx->grandmap.cur->up && obx->grandmap.cur->up.id != '1')
    {
        obx->grandmap.cur.id = '0';
        obx->grandmap.cur = obx->grandmap.cur->up;
        obx->grandmap.cur.id = 'S';
    }
	obx->minimap.center = obx->player.tile;
	update_bounding_box(obx);
}

static void	move_player_down(t_obx *obx, int i, int j)
{
	if (obx->grandmap.cur->down && obx->grandmap.cur->down.id != '1')
    {
        obx->grandmap.cur.id = '0';
        obx->grandmap.cur = obx->grandmap.cur->down;
        obx->grandmap.cur.id = 'S';
    }
	obx->minimap.center = obx->player.tile;
	update_bounding_box(obx);
}

static void	move_player_right(t_obx *obx, int i, int j)
{
	if (obx->grandmap.cur->right && obx->grandmap.cur->right.id != '1')
    {
        obx->grandmap.cur.id = '0';
        obx->grandmap.cur = obx->grandmap.cur->right;
        obx->grandmap.cur.id = 'S';
    }
	obx->minimap.center = obx->player.tile;
	update_bounding_box(obx);
}

static void	move_player_left(t_obx *obx, int i, int j)
{
    if (obx->grandmap.cur->left && obx->grandmap.cur->left.id != '1')
    {
        obx->grandmap.cur.id = '0';
        obx->grandmap.cur = obx->grandmap.cur->left;
        obx->grandmap.cur.id = 'S';
        obx->minimap.center.id = '0';
        obx->minimap.center = obx->minimap.center->left;
        obx->minimap.center.id = 'S';
    }
	obx->minimap.center = obx->player.tile;
	update_bounding_box(obx);
}

void	move_player(t_obx *obx, t_plane flag)
{
	if (flag.x0)
		move_player_up(obx, -1, -1);
	else if (flag.x)
		move_player_down(obx, -1, -1);
	else if (flag.y0)
		move_player_right(obx, -1, -1);
	else if (flag.y)
		move_player_left(obx, -1, -1);
}