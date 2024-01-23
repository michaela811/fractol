#include "fractol.h"

int key_handle(int keysym, t_fractol *fractol)
{
    if (keysym == XK_Escape)  //x on window?
        quit_handle(fractol);
    if (keysym == XK_plus)
        fractol -> iterations += 10;
    else if (keysym == XK_minus)
        fractol -> iterations -= 10;
    else if (keysym == XK_Left)
        fractol -> shift_x += (0.5 * fractol -> zoom);
    else if (keysym == XK_Right) 
        fractol -> shift_x -= (0.5 * fractol -> zoom);
    else if (keysym == XK_Up)
        fractol -> shift_y -= (0.5 * fractol -> zoom);
    else if (keysym == XK_Down)
        fractol -> shift_x += (0.5 * fractol -> zoom);
    fractol_render(fractol);
    return (0);
}

int mouse_handle(int button, int x, int y, t_fractol *fractol)
{
    if (button == Button5)
        fractol -> zoom *= 0.95;
    else if (button == Button4)
        fractol -> zoom *= 1.05;
    fractol_render(fractol);
    return (0);
}

int quit_handle(t_fractol *fractol)
{
    mlx_destroy_image(fractol -> connection, fractol ->img.img_ptr);
	mlx_destroy_window(fractol -> connection, fractol -> window);
	mlx_destroy_display(fractol -> connection);
	free(fractol -> connection);
	exit(EXIT_SUCCESS);
}
int	julia(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol -> name, "julia", 5))
	{
		fractol -> julia_x = (scale(x, -2, +2, SIDE_LENGHT) * fractol -> zoom) + fractol -> shift_x;
		fractol -> julia_y = (scale(y, +2, -2, SIDE_LENGHT) * fractol -> zoom) + fractol -> shift_y;
		fractol_render(fractol);
	}
	return (0);
}
