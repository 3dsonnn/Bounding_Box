/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:34:10 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 23:42:04 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"

void	free_tiles(t_obx *obx)
{
	int	i;

	i = -1;
	while (++i < obx->map.size.y)
		free(obx->tiles[i]);
	free(obx->tiles);
}
