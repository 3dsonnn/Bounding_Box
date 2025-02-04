/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_obx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:24:23 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 08:00:21 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

static  t_tile  *get_topleft(t_obx *obx, t_tile  *tmp, int i)
{
    while (++i < 5)
    {
        if (tmp->upleft)
        {
            tmp = tmp->upleft;
            continue ;
        }
        break ;
    }
    return (tmp);
}

static  t_tile  *get_topright(t_obx *obx, t_tile  *tmp, int i)
{
    while (++i < 5)
    {
        if (tmp->upright)
        {
            tmp = tmp->upright;
            continue ;
        }
        break ;
    }
    return (tmp);
}

static  t_tile  *get_bottleft(t_obx *obx, t_tile  *tmp, int i)
{
    while (++i < 5)
    {
        if (tmp->downleft)
        {
            tmp = tmp->downleft;
            continue ;
        }
        break ;
    }
    return (tmp);
}


static  t_tile  *get_bottright(t_obx *obx, t_tile  *tmp, int i)
{
    while (++i < 5)
    {
        if (tmp->downright)
        {
            tmp = tmp->downright;
            continue ;
        }
        break ;
    }
    return (tmp);
}

void    update_obx(t_obx *obx)
{
    if (!obx->minimap.box)
        return ;
    obx->minimap.corners[TOPLEFT] = get_topleft(obx, obx->cur, -1);
    obx->minimap.corners[TOPRIGHT] = get_topright(obx, obx->cur, -1);
    obx->minimap.corners[BOTTLEFT] = get_bottleft(obx, obx->cur, -1);
    obx->minimap.corners[BOTTRIGHT] = get_bottright(obx, obx->cur, -1);
}
