/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:35 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 05:01:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static int	my_mlx_close(t_obx *obx)
{
	mlx_destroy_image(obx->mlx, obx->grandmap.big.img);
	mlx_destroy_image(obx->mlx, obx->minimap.lil.img);
	mlx_destroy_window(obx->mlx, obx->win);
	mlx_destroy_display(obx->mlx);
	free(obx->mlx);
	exit(0);
}

static int	my_mlx_key_press(int keycode, t_obx *obx)
{
	if (keycode == ESC)
		my_mlx_close(obx);
	else if (keycode == UP)
		move_player(obx, (t_plane){1, 0, 0, 0});
	else if (keycode == DOWN)
		move_player(obx, (t_plane){0, 1, 0, 0});
	else if (keycode == RIGHT)
		move_player(obx, (t_plane){0, 0, 1, 0});
	else if (keycode == LEFT)
		move_player(obx, (t_plane){0, 0, 0, 1});
	else
		return (0);
	bounding_box(obx);
	return (0);
}

static int	my_mlx_mouse_motion(int x, int y, t_obx *obx)
{
    (void)obx;
	printf("Mouse position: x=%d\ty=%d\n", x, y);
	return (0);
}

void	my_mlx_hook(t_obx *obx)
{
	mlx_hook(obx->win, 2, 1L << 0, my_mlx_key_press, obx);
	mlx_hook(obx->win, 17, 1L << 17, my_mlx_close, obx);
    mlx_hook(obx->win, 6, 1L << 6, my_mlx_mouse_motion, obx);
}
