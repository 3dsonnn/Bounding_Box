/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:59 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 09:32:51 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void	paint_minimap_tile(t_obx *obx, int i, int j, int color)
{
	int	x0;
	int	x;
	int	y0;
	int	y;

	y0 = i * obx->minimap.tilesize;
	x = (j + 1) * obx->minimap.tilesize;
	y = (i + 1) * obx->minimap.tilesize;
	while (y0 < y)
	{
		x0 = j * obx->minimap.tilesize;
		while (x0 < x)
		{
			if (x0 == j * obx->minimap.tilesize || x0 == x - 1 || y0 == i
				* obx->minimap.tilesize || y0 == y - 1)
				my_mlx_pixel_put(&obx->minimap.img, x0, y0, 0xFFFFFF);
			else
				my_mlx_pixel_put(&obx->minimap.img, x0, y0, color);
			x0++;
		}
		y0++;
	}
}

static  void	paint_background_tile(t_obx *obx, int i, int j, int color)
{
	int	x0;
	int	x;
	int	y0;
	int	y;

	y0 = i * obx->background_tilesize;
	x = (j + 1) * obx->background_tilesize;
	y = (i + 1) * obx->background_tilesize;
	while (y0 < y)
	{
		x0 = j * obx->background_tilesize;
		while (x0 < x)
		{
			if (x0 == j * obx->background_tilesize || x0 == x - 1 || y0 == i
				* obx->background_tilesize || y0 == y - 1)
				my_mlx_pixel_put(&obx->background_img, x0, y0, 0xFFFFFF);
			else
				my_mlx_pixel_put(&obx->background_img, x0, y0, color);
			x0++;
		}
		y0++;
	}
}

void	bounding_box(t_obx *obx, int i, int j)
{
    while (++i < obx->map.size.y)
    {
        j = -1;
        while (++j < obx->map.size.x)
                paint_background_tile(obx, i, j, obx->tiles[i][j].color);
    }
    mlx_put_image_to_window(obx->mlx, obx->win, obx->background_img.img, 0, 0);
	if (obx->minimap.box)
		paint_obx(obx, obx->minimap.corners[TOPLEFT], obx->minimap.corners[TOPLEFT]);
	else
	{
        i = -1;
		while (++i < obx->map.size.y)
		{
			j = -1;
			while (++j < obx->map.size.x)
					paint_minimap_tile(obx, i, j, obx->tiles[i][j].color);
		}
	}
	mlx_put_image_to_window(obx->mlx, obx->win, obx->minimap.img.img, WIDTH - 220, 0);
}
