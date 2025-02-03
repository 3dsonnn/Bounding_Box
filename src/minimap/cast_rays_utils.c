/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:35:12 by efinda            #+#    #+#             */
/*   Updated: 2025/01/24 16:01:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	draw_ray(t_cub *cub, t_ray ray)
{
    t_plane	line;

    line = cub->player.pos;
    if (ray.dhor < ray.dvert)
    {
        line.x = ray.hor.x;
        line.y = ray.hor.y;
    }
    else
    {
        line.x = ray.vert.x;
        line.y = ray.vert.y;
    }
    bresenham_line(cub, line, (t_point){0, 0}, (t_point){0, 0});
}
