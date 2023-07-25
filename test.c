#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>

#define WIDTH 5
#define HEIGHT 4
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define DEG_TO_RAD (3.141592653589793 / 180.0)
#define ZOOM 50
#define SHIFT_X WIN_WIDTH / 2
#define SHIFT_Y WIN_HEIGHT / 2

typedef struct {
    double z;
    int color;
    double iso_x;
    double iso_y;
} t_point;

void isometric_projection(t_point points[HEIGHT][WIDTH]) {
    double iso_angle = 35.26 * DEG_TO_RAD;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int original_x = x;
            int original_y = y;

            double iso_x = (original_y - original_x) * cos(iso_angle);
            double iso_y = (original_y + original_x) * sin(iso_angle) - points[y][x].z;

            points[y][x].iso_x = iso_x;
            points[y][x].iso_y = iso_y;
        }
    }
}


void apply_zoom_and_shift(t_point points[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            points[y][x].iso_x = points[y][x].iso_x * ZOOM + SHIFT_X;
            points[y][x].iso_y = points[y][x].iso_y * ZOOM + SHIFT_Y;
        }
    }
}

void draw_line(t_point start, t_point end, void *mlx_ptr, void *win_ptr) {
    int dx = abs((int)end.iso_x - (int)start.iso_x);
    int dy = abs((int)end.iso_y - (int)start.iso_y);
    int sx = (start.iso_x < end.iso_x) ? 1 : -1;
    int sy = (start.iso_y < end.iso_y) ? 1 : -1;
    int err = dx - dy;
    int x = (int)start.iso_x;
    int y = (int)start.iso_y;

    while (x != (int)end.iso_x || y != (int)end.iso_y) {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF); // Set the pixel at (x, y) to white (0xFFFFFF)
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}




int main() {
    void *mlx_ptr;
    void *win_ptr;
    
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Isometric Line");

    t_point points[HEIGHT][WIDTH] = {
        { {0, 0, 0, 0}, {0, 10, 0, 1}, {0, 10, 0, 2}, {0, 10, 0, 3}, {0, 0, 0, 4} },
        { {0, 0, 1, 0}, {0, 10, 1, 1}, {0, 10, 1, 2}, {0, 10, 1, 3}, {0, 0, 1, 4} },
        { {0, 0, 2, 0}, {0, 10, 2, 1}, {0, 10, 2, 2}, {0, 10, 2, 3}, {0, 0, 2, 4} },
        { {0, 0, 3, 0}, {0, 10, 3, 1}, {0, 10, 3, 2}, {0, 10, 3, 3}, {0, 0, 3, 4} }
    };

   isometric_projection(points);
    apply_zoom_and_shift(points);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH - 1; x++) {
            draw_line(points[y][x], points[y][x + 1], mlx_ptr, win_ptr);
        }
    }

    for (int y = 0; y < HEIGHT - 1; y++) {
        for (int x = 0; x < WIDTH; x++) {
            draw_line(points[y][x], points[y + 1][x], mlx_ptr, win_ptr);
        }
    }

    mlx_loop(mlx_ptr);
    return 0;
}

