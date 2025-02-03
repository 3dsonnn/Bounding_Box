/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:50:36 by efinda            #+#    #+#             */
/*   Updated: 2025/01/26 19:12:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum IFPOS
{
	IFUP,
	IFDOWN,
	IFLEFT,
	IFRIGHT,
	IFUPLEFT,
	IFUPRIGHT,
	IFDOWNLEFT,
	IFDOWNRIGHT
}					t_IFPOS;

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

typedef struct s_plane
{
	int				x0;
	int				x;
	int				y0;
	int				y;
}					t_plane;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_tile
{
	int				active;
	t_plane			pos;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
	struct s_tile	*upleft;
	struct s_tile	*upright;
	struct s_tile	*downleft;
	struct s_tile	*downright;
}					t_tile;

typedef struct s_tbr
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_tile			**tiles;
	int				tilewidth;
	int				tileheight;
}					t_tbr;

#endif