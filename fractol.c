#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol   fractol;

    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) ||
        (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        fractol.name = argv[1];
        if (!ft_strncmp(fractol.name, "julia", 5))
        {
            fractol.julia_x = ft_char_to_double(argv[2]);
            fractol.julia_y = ft_char_to_double(argv[3]);
        }
        init_function(&fractol);
        fractol_render(&fractol);
        mlx_loop(fractol.connection);
    }
    else
    {
        return(write(1, "You entered invalid or no parameter.\nPlease try again and enter one of these parameters:\n     \"mandelbrot\" or\n     \"julia\" \"<value_1>\" \"<value_2>\"\n", 150), 0);
        return (0);
    }
}
