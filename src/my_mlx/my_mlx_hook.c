/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:33:35 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 18:43:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/TBR.h"

static int	my_mlx_close(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(cub->mlx, cub->scene.walls[i].img.img);
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}

static int	my_mlx_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		my_mlx_close(cub);
	else if (keycode == WKEY)
		move_player(cub, (t_plane){1, 0, 0, 0});
	else if (keycode == SKEY)
		move_player(cub, (t_plane){0, 1, 0, 0});
	else if (keycode == DKEY)
		move_player(cub, (t_plane){0, 0, 1, 0});
	else if (keycode == AKEY)
		move_player(cub, (t_plane){0, 0, 0, 1});
	else if (keycode == RIGHT)
		rotate_player(cub, 1);
	else if (keycode == LEFT)
		rotate_player(cub, 0);
	if (cub->flag)
		cub3D(cub);
	return (0);
}

static int	my_mlx_mouse_motion(int x, int y, t_cub *cub)
{
    (void)cub;
	printf("Mouse position: x=%d\ty=%d\n", x, y);
	return (0);
}

void	my_mlx_hook(t_cub *cub)
{
	mlx_hook(cub->win, 2, 1L << 0, my_mlx_key_press, cub);
	mlx_hook(cub->win, 17, 1L << 17, my_mlx_close, cub);
    mlx_hook(cub->win, 6, 1L << 6, my_mlx_mouse_motion, cub);
}
