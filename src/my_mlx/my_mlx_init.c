/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:40:46 by efinda            #+#    #+#             */
/*   Updated: 2025/02/04 04:40:11 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void	my_mlx_init(t_obx *obx)
{
	obx->mlx = mlx_init();
	obx->win = mlx_new_window(obx->mlx, WIDTH, HEIGHT, "Bounding Box");
	init_grandmap(obx, -1);
	init_lilmap(obx, -1);
    ft_mtxfree(&obx->map.content);
}
