/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:13:09 by mmasarov          #+#    #+#             */
/*   Updated: 2024/01/23 16:13:20 by mmasarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_char_to_double(char *s)
{
	long	int_part;
	double	float_part;
	double	d;
	int		minus;

	int_part = 0;
	float_part = 0;
	minus = 0;
	d = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			minus = -1;
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		d /= 10;
		float_part = float_part + (*s++ - '0') * d;
	}
	return ((int_part + float_part) * minus);
}
