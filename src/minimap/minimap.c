/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:53 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 18:01:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/TBR.h"

static	void	paint_tile(t_cub *cub, t_tile tile)
{
	int	x0;
	int	x;
	int	y0;
	int	y;

	y0 = tile.pos.y0;
	x = tile.pos.x;
	y = tile.pos.y;
	while (y0 < y)
	{
		x0 = tile.pos.x0;
		while (x0 < x)
		{
			if (x0 == tile.pos.x0 || x0 == x - 1 || y0 == tile.pos.y0 || y0 == y - 1)
				my_mlx_pixel_put(&cub->minimap.img, x0, y0, 0xFFFFFF);
			else
				my_mlx_pixel_put(&cub->minimap.img, x0, y0, tile.color);
			x0++;
		}
		y0++;
	}
}

void	minimap(t_cub *cub, int i, int j)
{
	while (++i < cub->scene.map.size.y)
	{
		j = -1;
		while (++j < cub->scene.map.size.x)
				paint_tile(cub, cub->minimap.tiles[i][j]);
	}
	draw_player(cub);
	draw_fov(cub);
	//cast_rays(cub, -1);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->minimap.img.img, 60, 30);
}
