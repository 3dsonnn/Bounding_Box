/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:59 by efinda            #+#    #+#             */
/*   Updated: 2025/02/06 01:26:22 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/obx.h"
#include <stdbool.h> // For bool type

// Helper function to draw a single pixel (reduces code duplication)
static inline void draw_pixel(t_img *img, int x, int y, int color) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) { // Boundary check
        my_mlx_pixel_put(img, x, y, color);
    }
}

// Optimized tile painting function with boundary checks
void paint_minimap_tile(t_obx *obx, int i, int j, int color) {
    int tileSize = obx->minimap.tilesize;
    int x0 = j * tileSize;
    int y0 = i * tileSize;
    int xEnd = x0 + tileSize;
    int yEnd = y0 + tileSize;

    // Pre-calculate boundary coordinates
    int borderX0 = x0;
    int borderX1 = xEnd - 1;
    int borderY0 = y0;
    int borderY1 = yEnd - 1;

    // Check if tile is within minimap bounds
    if (x0 < 0 || x0 >= obx->minimap.img.width || y0 < 0 || y0 >= obx->minimap.img.height) {
        return; // Out of bounds, don't draw
    }
      if (xEnd < 0 || xEnd >= obx->minimap.img.width || yEnd < 0 || yEnd >= obx->minimap.img.height) {
        return; // Out of bounds, don't draw
    }

    for (int y = y0; y < yEnd; y++) {
        for (int x = x0; x < xEnd; x++) {
            // Draw border or fill color
            if (x == borderX0 || x == borderX1 || y == borderY0 || y == borderY1) {
                draw_pixel(&obx->minimap.img, x, y, 0xFFFFFF); // White border
            } else {
                draw_pixel(&obx->minimap.img, x, y, color);
            }
        }
    }
}


static void paint_background_tile(t_obx *obx, int i, int j, int color) {
    int tileSize = obx->background_tilesize;
    int x0 = j * tileSize;
    int y0 = i * tileSize;
    int xEnd = x0 + tileSize;
    int yEnd = y0 + tileSize;

    // Pre-calculate boundary coordinates
    int borderX0 = x0;
    int borderX1 = xEnd - 1;
    int borderY0 = y0;
    int borderY1 = yEnd - 1;

     // Check if tile is within background image bounds
    if (x0 < 0 || x0 >= obx->background_img.width || y0 < 0 || y0 >= obx->background_img.height) {
        return;  // Don't draw out of bounds
    }
    if (xEnd < 0 || xEnd >= obx->background_img.width || yEnd < 0 || yEnd >= obx->background_img.height) {
        return; // Out of bounds, don't draw
    }


    for (int y = y0; y < yEnd; y++) {
        for (int x = x0; x < xEnd; x++) {
            // Draw border or fill
            if (x == borderX0 || x == borderX1 || y == borderY0 || y == borderY1) {
                draw_pixel(&obx->background_img, x, y, 0xFFFFFF); // White border
            } else {
                draw_pixel(&obx->background_img, x, y, color);
            }
        }
    }
}


// Optimized main drawing function
void bounding_box(t_obx *obx) {
    // 1. Pre-calculate frequently used values.  This avoids *repeatedly*
    //    accessing struct members inside the loops.
    int mapSizeX = obx->map.size.x;
    int mapSizeY = obx->map.size.y;
    t_tile **tiles = obx->tiles; // Direct pointer to the tile array
    t_minimap *minimap = &obx->minimap; // Pointer to the minimap for efficiency

    // 2. Draw the background (only once, outside the nested loops)
      for (int i = 0; i < mapSizeY; i++)
    {
        for (int j = 0; j < mapSizeX; j++)
        {
            paint_background_tile(obx, i, j, tiles[i][j].color);
        }
    }
    mlx_put_image_to_window(obx->mlx, obx->win, obx->background_img.img, 0, 0);

    // 3. Draw the minimap or bounding box
    if (minimap->box) {
        paint_obx(obx, minimap->corners[TOPLEFT]); //  paint the character on top
    } else {
        // Optimized minimap drawing loop
          for (int i = 0; i < mapSizeY; i++)
        {
            for (int j = 0; j < mapSizeX; j++)
            {
               paint_minimap_tile(obx, i, j, tiles[i][j].color);
            }
        }
    }

    // 4. Put the minimap image to the window (only once)
    mlx_put_image_to_window(obx->mlx, obx->win, minimap->img.img, WIDTH - 220, 0);
}

//Add this to obx.h
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     width;        // Add width
    int     height;       // Add height
}				t_img;

// Modify this function, it should be somewhere in your initialization code
// to set the width and height when you create an image.
void initialize_images(t_obx *obx) {
    // ... your other initialization code ...

    obx->minimap.img.img = mlx_new_image(obx->mlx, 220, /*your minimap height*/);
    obx->minimap.img.addr = mlx_get_data_addr(obx->minimap.img.img, &obx->minimap.img.bits_per_pixel,
                                              &obx->minimap.img.line_length, &obx->minimap.img.endian);
    obx->minimap.img.width = 220;  // Example width
    obx->minimap.img.height = /* Calculate minimap height */;


    obx->background_img.img = mlx_new_image(obx->mlx, WIDTH, HEIGHT);
    obx->background_img.addr = mlx_get_data_addr(obx->background_img.img, &obx->background_img.bits_per_pixel,
                                                   &obx->background_img.line_length, &obx->background_img.endian);
    obx->background_img.width = WIDTH;
    obx->background_img.height = HEIGHT;

    // ... rest of your initialization ...
}
