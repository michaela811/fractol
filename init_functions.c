/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:27:49 by mmasarov          #+#    #+#             */
/*   Updated: 2024/01/24 14:45:50 by mmasarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_fractol *fractol)
{
	fractol -> escape_value = 4;
	fractol -> iterations = 50;
	fractol -> zoom = 0.85;
	if (!ft_strncmp(fractol -> name, "mandelbrot", 10))
	{
		fractol -> shift_x = -0.5;
		fractol -> shift_y = 0.0;
	}
	else
	{
		fractol -> shift_x = 0.0;
		fractol -> shift_y = 0.0;
	}
}

void	events_inits(t_fractol *fractol)
{
	mlx_hook(fractol -> window, KeyPress, KeyPressMask, key_handle, fractol);
	mlx_hook(fractol -> window, ButtonPress, ButtonPressMask, mouse_handle,
		fractol);
	mlx_hook(fractol -> window, DestroyNotify, StructureNotifyMask,
		quit_handle, fractol);
}

void	select_set(t_complex *z, t_complex *c, t_fractol *fractol)
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

void	init_function(t_fractol *fractol)
{
	fractol -> connection = mlx_init();
	if (fractol -> connection == NULL)
		error_message();
	fractol -> window = mlx_new_window(fractol -> connection, SIDE_LENGHT,
			SIDE_LENGHT, fractol -> name);
	if (fractol -> window == NULL)
		destroy_func(fractol);
	fractol -> img.img_ptr = mlx_new_image(fractol -> connection, SIDE_LENGHT,
			SIDE_LENGHT);
	if (fractol -> img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol -> connection, fractol -> window);
		destroy_func(fractol);
	}
	fractol -> img.pixel_ptr = mlx_get_data_addr(fractol -> img.img_ptr,
			&fractol -> img.bpp, &fractol -> img.line_len,
			&fractol -> img.endian);
	if (fractol -> img.pixel_ptr == NULL)
	{
		mlx_destroy_image(fractol -> connection, fractol -> img.img_ptr);
		mlx_destroy_window(fractol -> connection, fractol -> window);
		destroy_func(fractol);
	}
	events_inits(fractol);
	data_init(fractol);
}
