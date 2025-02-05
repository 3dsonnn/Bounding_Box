/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:50:36 by efinda            #+#    #+#             */
/*   Updated: 2025/02/05 22:04:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_CORNERS
{
	REF,
	REF_X,
	REF_Y,
}					t_CORNERS;

typedef struct s_iter
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	int				n;
}					t_iter;

typedef struct s_plane
{
	int				x0;
	int				x;
	int				y0;
	int				y;
}					t_plane;

typedef struct s_rows
{
	char			*str;
	struct s_rows	*next;
}					t_rows;

typedef struct s_img
{
	char			*addr;
	void			*img;
	int				bpp;
	int				width;
	int				height;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_map
{
	int				fd;
	char			*line;
	char			**content;
	t_point			size;
	t_point			start;
	t_rows			*head;
}					t_map;

typedef struct s_tile
{
	char			id;
	int				color;
	t_point			crd;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}					t_tile;

typedef struct s_mmap
{
	int				box;
	int				tilesize;
	t_tile			*refs[3];
	t_tile			**tiles;
	t_img			img;
}					t_mmap;

typedef struct s_obx
{
	void			*mlx;
	void			*win;
	t_tile			*cur;
	t_tile			**tiles;
	t_mmap			minimap;
	t_img			background_img;
	int				background_tilesize;
	t_map			map;
}					t_obx;

#endif