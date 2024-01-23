#include "fractol.h"

void    put_pixel(int x, int y, t_img *img, int color)
{
    int offset;

    offset = (y * img -> line_len) + (x * (img -> bpp / 8));
    *(unsigned int *)(img -> pixel_ptr + offset) = color;
}

void    fractol_render(t_fractol *fractol)
{
    int x;
    int  y;

    y = 0;
    while (y < SIDE_LENGHT)
    {
        x = 0;
        while (x < SIDE_LENGHT)
        {
            handle_pixel(x, y, fractol);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol -> connection, fractol -> window, fractol -> img.img_ptr, 0, 0);
}

void    handle_pixel(int x, int y, t_fractol *fractol)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = (scale(x, -2, 2, SIDE_LENGHT) * fractol -> zoom) + fractol -> shift_x;
    z.y = (scale(y, 2, -2, SIDE_LENGHT) * fractol -> zoom) + fractol -> shift_y;
    select_set(&z, &c, fractol);
    while (i < fractol -> iterations) // TODO do it until
    {
        z = sum_complex(square_complex(z), c); // maybe move this function elsewhere
        if (((z.x * z.x) * (z.y * z.y)) > fractol -> escape_value)
        {
            color = scale(i, BLACK, WHITE, fractol -> iterations); 
            put_pixel(x, y, &fractol -> img, color);
            return ;
        }
        i++;  
    }
    put_pixel(x, y, &fractol -> img, SEA_GREEN);
}

void    select_set(t_complex *z, t_complex *c, t_fractol *fractol)
{
    if (!ft_strncmp(fractol -> name, "julia", 5))
	{
		c -> x = fractol -> julia_x;
		c -> y = fractol -> julia_y;
	}
	else
	{
		c -> x = z -> x;
		c -> y = z -> y;
	}
}