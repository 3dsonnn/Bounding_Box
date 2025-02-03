/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:40:46 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 18:46:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/TBR.h"

void	my_mlx_init(t_tbr *tbr)
{
	tbr->mlx = mlx_init();
	tbr->win = mlx_new_window(tbr->mlx, WIDTH, HEIGHT, "Tile-Based Rendering");
	tbr->img.img = mlx_new_image(tbr->mlx, WIDTH, HEIGHT);
	tbr->img.addr = mlx_get_data_addr(tbr->img.img, &tbr->img.bpp,
			&tbr->img.line_len, &tbr->img.endian);
}
