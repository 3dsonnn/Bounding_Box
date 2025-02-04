/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_obx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:01:30 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 08:29:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static int	get_delta_x(t_tile *left, t_tile *right)
{
    int i;
    int res;

    i = -1;
    res = 0;
    while (++i < 11)
    {
        if (left && left != right)
        {
            left = left->right;
            res++;
            continue ;
        }
        if (left == right)
            res++;
        break ;
    }
    return (res);
}

static int	get_delta_y(t_tile *top, t_tile *bottom)
{
    int i;
    int res;

    i = -1;
    res = 0;
    while (++i < 11)
    {
        if (top && top != bottom)
        {
            top = top->down;
            res++;
            continue ;
        }
        if (top == bottom)
            res++;
        break ;
    }
    return (res);
}

void	paint_obx(t_obx *obx, t_tile *cur, t_tile *y)
{
	t_plane dist;
    
    dist.y0 = -1;
    dist.x = get_delta_x(obx->minimap.corners[TOPLEFT], obx->minimap.corners[TOPRIGHT]);
	dist.y = get_delta_y(obx->minimap.corners[TOPLEFT], obx->minimap.corners[BOTTLEFT]);
    while (++(dist.y0) < dist.y)
    {
        dist.x0 = -1;
        while (++(dist.x0) < dist.x)
        {
            paint_minimap_tile(obx, dist.y0, dist.x0, cur->color);
            cur = cur->right;
        }
        y = y->down;
        cur = y;
    }
}