/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:59:36 by efinda            #+#    #+#             */
/*   Updated: 2025/01/24 16:37:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static int	is_wall(t_cub *cub, double x, double y)
{
	int		i;
	int		j;
	t_point	point;

	i = -1;
	j = -1;
	point.x = (int)floor(x);
	point.y = (int)floor(y);
	if (point.x < 0 || point.y < 0)
		return (1);
	while (++i < cub->scene.map.size.y)
	{
		j = -1;
		while (++j < cub->scene.map.size.x)
		{
			if (cub->minimap.tiles[i][j].id == '1'
				&& check_if_same_tile(cub->minimap.tiles[i][j].pos,
					cub->minimap.tiles[i][j].pos.x0, point.x, point.y))
				return (1);
		}
	}
	return (0);
}

static int	is_within_map(t_cub *cub, double x, double y)
{
	t_point	point;

	point.x = (int)floor(x);
	point.y = (int)floor(y);
	if (point.x < 0 || point.y < 0 || point.x >= cub->minimap.tilewidth
		|| point.y >= cub->minimap.tileheight)
		return (0);
	return (1);
}

static void	check_horizontal_intersection(t_cub *cub, t_ray *ray)
{
	if (ray->face.y)
		ray->hor.y = floor(cub->player.pos.y0 / cub->minimap.tileheight)
			* cub->minimap.tileheight + cub->minimap.tileheight;
	else
		ray->hor.y = floor(cub->player.pos.y0 / cub->minimap.tileheight)
			* cub->minimap.tileheight - 1;
	ray->step.x = cub->minimap.tileheight / ray->tan;
	if (ray->face.y)
		ray->step.y = cub->minimap.tileheight;
	else
		ray->step.y = -cub->minimap.tileheight;
	ray->hor.x = cub->player.pos.x0 + (ray->hor.y - cub->player.pos.y0)
		/ ray->tan;
	while (is_within_map(cub, ray->hor.x, ray->hor.y) && !is_wall(cub,
			ray->hor.x, ray->hor.y))
	{
		ray->hor.x += ray->step.x;
		ray->hor.y += ray->step.y;
	}
	ray->dhor = sqrt(pow(ray->hor.x - cub->player.pos.x0, 2) + pow(ray->hor.y
				- cub->player.pos.y0, 2));
}

static void	check_vertical_intersection(t_cub *cub, t_ray *ray)
{
	if (ray->face.x)
		ray->vert.x = floor(cub->player.pos.x0 / cub->minimap.tilewidth)
			* cub->minimap.tilewidth + cub->minimap.tilewidth;
	else
		ray->vert.y = floor(cub->player.pos.x0 / cub->minimap.tilewidth)
			* cub->minimap.tilewidth - 1;
	ray->step.y = ray->tan * cub->minimap.tilewidth;
	if (ray->face.x)
		ray->step.x = cub->minimap.tilewidth;
	else
		ray->step.x = -cub->minimap.tilewidth;
	ray->vert.y = cub->player.pos.y0 + (ray->vert.x - cub->player.pos.x0)
		* ray->tan;
	while (is_within_map(cub, ray->vert.x, ray->vert.y) && !is_wall(cub,
			ray->vert.x, ray->vert.y))
	{
		ray->vert.x += ray->step.x;
		ray->vert.y += ray->step.y;
	}
	ray->dvert = sqrt(pow(ray->vert.x - cub->player.pos.x0, 2) + pow(ray->vert.y
				- cub->player.pos.y0, 2));
}

void	cast_rays(t_cub *cub, int i)
{
	t_ray	ray;

	while (++i < cub->minimap.miniwidth)
	{
		ray.angle = cub->player.fov.x + i * cub->player.ray_step;
		ray.angle = fmod(ray.angle + 360.0, 360.0);
		ray.tan = tan(ray.angle * M_PI / 180.0);
		ray.face.x = (ray.angle < 90.0 || ray.angle > 270.0);
		ray.face.y = (ray.angle > 0.0 && ray.angle < 180.0);
		if (fabs(ray.tan) < 1e-6)
			ray.tan = 1e-6;
		check_horizontal_intersection(cub, &ray);
		check_vertical_intersection(cub, &ray);
		draw_ray(cub, ray);
	}
}
