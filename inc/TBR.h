/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TBR.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:27:58 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 19:07:31 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TBR_H
# define TBR_H

# include "../libft/libft.h"
# include "mlx.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

# define ESC 65307

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define NUMLEFT 65430
# define NUMRIGHT 65432
# define NUMUP 65431
# define NUMUPLEFT 65429
# define NUMUPRIGHT 65434
# define NUMDOWN 65433
# define NUMDOWNLEFT 65436
# define NUMDOWNRIGHT 65435

//    MLX
int		my_mlx_get_rgb_color(int r, int g, int b);
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);

#endif