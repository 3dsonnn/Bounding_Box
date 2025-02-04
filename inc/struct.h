/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:50:36 by efinda            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/04 05:34:51 by efinda           ###   ########.fr       */
=======
/*   Updated: 2025/02/04 07:38:08 by efinda           ###   ########.fr       */
>>>>>>> 3c36654 (rendering both the background and minimap, but I can't still make it move, idw but I'll find out)
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_CORNERS
{
	TOPLEFT,
	TOPRIGHT,
	BOTTLEFT,
	BOTTRIGHT
}					t_CORNERS;
<<<<<<< HEAD

typedef struct s_dpoint
{
	double			x;
	double			y;
}					t_dpoint;

typedef struct s_dplane
{
	double			x0;
	double			x;
	double			y0;
	double			y;
}					t_dplane;
=======
>>>>>>> 3c36654 (rendering both the background and minimap, but I can't still make it move, idw but I'll find out)

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
	struct s_tile	*upleft;
	struct s_tile	*upright;
	struct s_tile	*downleft;
	struct s_tile	*downright;
}					t_tile;

typedef struct s_mmap
{
	int				box;
	int				tilesize;
	t_tile			*corners[4];
	t_tile			**tiles;
<<<<<<< HEAD
	t_img			lil;
}					t_mmap;

typedef struct s_gmap
{
	int				tilesize;
	t_img			big;
}					t_gmap;

=======
	t_img			img;
}					t_mmap;

>>>>>>> 3c36654 (rendering both the background and minimap, but I can't still make it move, idw but I'll find out)
typedef struct s_obx
{
	void			*mlx;
	void			*win;
	t_tile			*cur;
	t_tile			**tiles;
	t_mmap			minimap;
<<<<<<< HEAD
	t_gmap			grandmap;
=======
	t_img			background_img;
	int				background_tilesize;
>>>>>>> 3c36654 (rendering both the background and minimap, but I can't still make it move, idw but I'll find out)
	t_map			map;
}					t_obx;

#endif