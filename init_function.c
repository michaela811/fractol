#include "fractol.h"

void    data_init(t_fractol *fractol)
{
    fractol -> escape_value = 4; // 2 squared, prepona?
    fractol -> iterations = 1000;
    fractol -> zoom = 1.0;
    fractol -> shift_x = 0.0;
    fractol -> shift_y = 0.0;
}

void    events_inits(t_fractol *fractol)
{
    mlx_hook(fractol -> window, KeyPress, KeyPressMask, key_handle, fractol);
    mlx_hook(fractol -> window, ButtonPress, ButtonPressMask, mouse_handle, fractol);
    mlx_hook(fractol -> window, DestroyNotify, StructureNotifyMask, quit_handle, fractol);
    mlx_hook(fractol -> window, MotionNotify, PointerMotionMask, julia, fractol);
}

void    init_function(t_fractol *fractol)
{
    fractol -> connection = mlx_init();
    if (fractol -> connection == NULL)
        error_message();
    fractol -> window = mlx_new_window(fractol -> connection, SIDE_LENGHT,
                                        SIDE_LENGHT, fractol -> name);
    if (fractol -> window == NULL)
    {
        mlx_destroy_display(fractol -> connection);
        free(fractol -> connection);
        error_message();
    }
    fractol -> img.img_ptr = mlx_new_image(fractol -> connection, SIDE_LENGHT, SIDE_LENGHT);
    if (fractol -> img.img_ptr == NULL)
    {
        mlx_destroy_window(fractol -> connection, fractol -> window); 
        mlx_destroy_display(fractol -> connection);
        free(fractol -> connection);
        error_message();
    }
    fractol -> img.pixel_ptr = mlx_get_data_addr(fractol -> img.img_ptr, 
                                                &fractol -> img.bpp, 
                                                &fractol -> img.line_len, 
                                                &fractol -> img.endian);
    if (fractol -> img.pixel_ptr == NULL)
    {
        mlx_destroy_image(fractol -> connection, fractol -> img.img_ptr); //is it necessary?
        mlx_destroy_window(fractol -> connection, fractol -> window); 
        mlx_destroy_display(fractol -> connection);
        free(fractol -> connection);
        error_message();
    }
    events_inits(fractol);
    data_init(fractol);
}

void    error_message(void)
{
    perror("Malloc failure: \n");
    exit(1);
}