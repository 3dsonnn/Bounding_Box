/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 05:03:00 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 23:53:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/obx.h"

static void	move_player_up(t_obx *obx)
{
	if (obx->cur->up && obx->cur->up->id != '1')
	{
		obx->cur->id = '0';
		obx->cur->color = WHITE;
		obx->cur = obx->cur->up;
		obx->cur->id = 'S';
		obx->cur->color = RED;
		update_obx(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1,
			-1, -1, -1});
	}
}

static void	move_player_down(t_obx *obx)
{
	if (obx->cur->down && obx->cur->down->id != '1')
	{
		obx->cur->id = '0';
		obx->cur->color = WHITE;
		obx->cur = obx->cur->down;
		obx->cur->id = 'S';
		obx->cur->color = RED;
		update_obx(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1,
			-1, -1, -1});
	}
}

static void	move_player_right(t_obx *obx)
{
	if (obx->cur->right && obx->cur->right->id != '1')
	{
		obx->cur->id = '0';
		obx->cur->color = WHITE;
		obx->cur = obx->cur->right;
		obx->cur->id = 'S';
		obx->cur->color = RED;
		update_obx(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1,
			-1, -1, -1});
	}
}

static void	move_player_left(t_obx *obx)
{
	if (obx->cur->left && obx->cur->left->id != '1')
	{
		obx->cur->id = '0';
		obx->cur->color = WHITE;
		obx->cur = obx->cur->left;
		obx->cur->id = 'S';
		obx->cur->color = RED;
		update_obx(obx, obx->cur, (t_plane){0, 0, 0, 0}, (t_iter){-1, -1, -1,
			-1, -1, -1});
	}
}

void	move_player(t_obx *obx, t_plane flag)
{
	if (flag.x0)
		move_player_up(obx);
	else if (flag.x)
		move_player_down(obx);
	else if (flag.y0)
		move_player_right(obx);
	else if (flag.y)
		move_player_left(obx);
}
