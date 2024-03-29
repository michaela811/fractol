/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:27:28 by mmasarov          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:18 by mmasarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "julia", 5))
		{
			fractol.julia_x = ft_atof(argv[2]);
			fractol.julia_y = ft_atof(argv[3]);
		}
		init_function(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.connection);
	}
	else
		invalid_input();
	return (0);
}
