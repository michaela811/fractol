/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:54:00 by mmasarov          #+#    #+#             */
/*   Updated: 2024/01/25 16:03:03 by mmasarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	perror("Malloc failure: \n");
	exit(1);
}

void	destroy_func(t_fractol *fractol)
{
	mlx_destroy_display(fractol -> connection);
	free(fractol -> connection);
	error_message();
}

void	invalid_input(void)
{
	ft_putstr_fd ("You entered invalid or no parameter.", 1);
	ft_putstr_fd ("\nPlease enter one of these parameters", 1);
	ft_putstr_fd (":\n     \"mandelbrot\" or\n     \"julia\"", 1);
	ft_putstr_fd (" \"<value_1>\" \"<value_2>\"\n", 1);
}
