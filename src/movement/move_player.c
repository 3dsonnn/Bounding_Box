/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:03:00 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 09:35:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static void	move_player_up(t_obx *obx, int i, int j)
{
	if (obx->cur->up && obx->cur->up->id != '1')
	{
        	obx->cur->id = '0';
        	obx->cur->color = 0xFFFFFF;
        	obx->cur = obx->cur->up;
       		obx->cur->id = 'S';
        	obx->cur->color = 0xFF0000;
		update_obx(obx);
	}
}

static void	move_player_down(t_obx *obx, int i, int j)
{
	if (obx->cur->down && obx->cur->down->id != '1')
    {
        obx->cur->id = '0';
        obx->cur->color = 0xFFFFFF;
        obx->cur = obx->cur->down;
        obx->cur->id = 'S';
        obx->cur->color = 0xFF0000;
	    update_obx(obx);
    }
}

static void	move_player_right(t_obx *obx, int i, int j)
{
	if (obx->cur->right && obx->cur->right->id != '1')
    {
        obx->cur->id = '0';
        obx->cur->color = 0xFFFFFF;
        obx->cur = obx->cur->right;
        obx->cur->id = 'S';
        obx->cur->color = 0xFF0000;
	    update_obx(obx);
    }
}

static void	move_player_left(t_obx *obx, int i, int j)
{
    if (obx->cur->left && obx->cur->left->id != '1')
    {
        obx->cur->id = '0';
        obx->cur->color = 0xFFFFFF;
        obx->cur = obx->cur->left;
        obx->cur->id = 'S';
        obx->cur->color = 0xFF0000;
	    update_obx(obx);
    }
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
