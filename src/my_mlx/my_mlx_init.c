/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:40:46 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 09:37:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static	void	init_minimap(t_obx *obx)
{
	int	max;

	if (obx->map.size.x < 11 || obx->map.size.y < 11)
	{
		if (obx->map.size.x > obx->map.size.y)
			max = obx->map.size.x;
		else
			max = obx->map.size.y;
		obx->minimap.tilesize = (int)floor(220 / max);
		obx->minimap.box = 0;
	}
	else
	{
		obx->minimap.tilesize = 20;
		obx->minimap.box = 1;
	}
	obx->minimap.img.width = 220;
	obx->minimap.img.height = 220;
	obx->minimap.img.img = mlx_new_image(obx->mlx, 220, 220);
	obx->minimap.img.addr = mlx_get_data_addr(obx->minimap.img.img, &obx->minimap.img.bpp, &obx->minimap.img.line_len, &obx->minimap.img.endian);
}

static	void	init_background(t_obx *obx)
{
	int	tmp[2];

	*tmp = (int)floor(WIDTH / obx->map.size.y);
	*(tmp + 1) = (int)floor(HEIGHT / obx->map.size.x);
	if (*tmp > *(tmp + 1))
		obx->background_tilesize = *(tmp + 1);
	else
		obx->background_tilesize = *tmp;
	obx->background_img.width = WIDTH;
	obx->background_img.height = HEIGHT;
    obx->background_img.img = mlx_new_image(obx->mlx, WIDTH, HEIGHT);
	obx->background_img.addr = mlx_get_data_addr(obx->background_img.img, &obx->background_img.bpp, &obx->background_img.line_len, &obx->background_img.endian);
}

void	my_mlx_init(t_obx *obx)
{
	int	i;

	i = -1;
	obx->mlx = mlx_init();
	obx->win = mlx_new_window(obx->mlx, WIDTH, HEIGHT, "Bounding Box");
    obx->tiles = (t_tile **)malloc(sizeof(t_tile *) * (obx->map.size.y));
	while (++i < obx->map.size.y)
	{
		obx->tiles[i] = (t_tile *)malloc(sizeof(t_tile) * obx->map.size.x);
		obx->tiles[i]->up = NULL;
		obx->tiles[i]->down = NULL;
		obx->tiles[i]->left = NULL;
		obx->tiles[i]->right = NULL;
		obx->tiles[i]->upleft = NULL;
		obx->tiles[i]->upright = NULL;
		obx->tiles[i]->downleft = NULL;
		obx->tiles[i]->downright = NULL;
	}
	link_tiles(obx, 0, 0);
	set_tiles(obx, -1, -1);
	init_background(obx);
	init_minimap(obx);
    	ft_mtxfree(&obx->map.content);
}
