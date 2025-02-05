/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_obx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:01:30 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 18:34:06 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void	paint_obx(t_obx *obx, t_tile *topleft)
{
    t_tile *tmp;
    t_point pos;

    pos = (t_point){-1, -1};
    while (++(pos.y) < 11 && topleft)
    {
        pos.x = -1;
        tmp = topleft;
        while (++(pos.x) < 11 && tmp)
        {
            paint_minimap_tile(obx, pos.y, pos.x, tmp->color);
            tmp = tmp->right;
        }
        topleft = topleft->down;
    }
    ft_printf("pos.y=%d\n", pos.y);
    ft_printf("topleft=%p\ttmp=%p\n", topleft, tmp);
}