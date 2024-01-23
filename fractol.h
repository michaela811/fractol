#ifndef FRACTOL_H
# define FRACTOL_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#define SIDE_LENGHT 800
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define GRAY 0x808080
#define LIGHT_GRAY 0xC0C0C0
#define DARK_GRAY 0x404040
#define PINK 0xFFC0CB
#define PURPLE 0x800080
#define ORANGE 0xFFA500
#define GOLD 0xFFD700
#define SILVER 0xC0C0C0
#define BRONZE 0xCD7F32
#define EMERALD_GREEN 0x50C878
#define FOREST_GREEN 0x228B22
#define SEA_GREEN 0x2E8B57

typedef struct  s_img
{
    void    *img_ptr;
    char    *pixel_ptr;
    int     bpp;  //bits per pixel 1 bit is 8 bytes
    int     line_len;
    int     endian;
}           t_img;

typedef struct s_complex
{
    double x;
    double y;
}           t_complex;

typedef struct s_fractol
{
    char    *name;
    void    *connection;
    void    *window;
    double  escape_value;
    int     iterations;
    double  zoom;
    double  julia_x;
    double  julia_y;
    double  shift_x;
    double  shift_y;
    t_img   img;
}   t_fractol;

// Init functions
void    init_function(t_fractol *fractol);
void    events_inits(t_fractol *fractol);
void    error_message(void);

// Fractol rendering functions
void    fractol_render(t_fractol *fractol);
void    handle_pixel(int x, int y, t_fractol *fractol);
void    put_pixel(int x, int y, t_img *img, int color);
void    select_set(t_complex *z, t_complex *c, t_fractol *fractol);

// Math functions
void        handle_pixel(int x, int y, t_fractol *fractol);
double      scale(double x, double new_min, double new_max, double old_max);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);

// Events functions
int mouse_handle(int button, int x, int y, t_fractol *fractol);
int key_handle(int keysym, t_fractol *fractol);
int quit_handle(t_fractol *fractol);
int	julia(int x, int y, t_fractol *fractol);

#endif