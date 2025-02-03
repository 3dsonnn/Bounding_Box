/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:58:45 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 19:20:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/TBR.h"

int	main(int ac, char **av)
{
	t_tbr	tbr;

	(void)av;
	if (ac != 1)
		return (write(2, "No args required\n",
				ft_strlen("No args required\n")));
	init_tbr(&tbr, -1, -1);
	my_mlx_init(&tbr);
	my_mlx_hook(&tbr);
	tbr(&tbr);
	mlx_loop(tbr.mlx);
	return (0);
}
