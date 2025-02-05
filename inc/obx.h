/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:27:58 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 15:39:51 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBX_H
# define OBX_H

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

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// MOVEMENT
void	move_player(t_obx *obx, t_plane flag);

// OBX
void	bounding_box(t_obx *obx, int i, int j);
void	update_obx(t_obx *obx, t_tile *cur, t_plane plane, t_iter iter);
void	paint_obx(t_obx *obx, t_tile *topleft);
void	paint_minimap_tile(t_obx *obx, int i, int j, int color);

//  CHECKS
void	checks(t_map *map, int ac, char **av);
void	fill_map(t_map *map);
void	check_starting_position(t_map *map);
void	is_surrounded(t_map *map);
void	exit_map(char *message, t_map *map);

//  MLX
void	my_mlx_init(t_obx *obx, int i, int j);
void	set_tiles(t_obx *obx, int i, int j);
void	link_tiles(t_obx *obx, int i, int j);
void	my_mlx_hook(t_obx *obx);
int		my_mlx_get_rgb_color(int r, int g, int b);
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);
void	my_mlx_clear_image(t_img *image);

//  T_ROW
char	**row_to_mtx(t_rows *head);
void	free_rows(t_rows **head);
t_rows	*new_row(char *str);
int		rowlen(t_rows *head);
void	add_row(t_rows **head, t_rows *_new);

#endif
