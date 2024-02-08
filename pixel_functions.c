/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:28:07 by mmasarov          #+#    #+#             */
/*   Updated: 2024/01/24 15:18:21 by mmasarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img -> line_len) + (x * (img -> bpp / 8));
	*(unsigned int *)(img -> pixel_ptr + offset) = color;
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(fractol -> connection, fractol
		-> window, fractol -> img.img_ptr, 0, 0);
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		color;

	i = 0;
	z.x = (scale(x, -2, 2, SIDE_LENGHT) * fractol -> zoom)
		+ fractol -> shift_x;
	z.y = (scale(y, 2, -2, SIDE_LENGHT) * fractol -> zoom)
		+ fractol -> shift_y;
	select_set(&z, &c, fractol);
	while (i < fractol -> iterations)
	{
		z = sum_complex(square_complex(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > fractol -> escape_value)
		{
			color = scale(i, BLACK, WHITE, fractol -> iterations);
			put_pixel(x, y, &fractol -> img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractol -> img, EMERALD_GREEN);
}
