/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:08:06 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 03:13:43 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(void *fract, t_complex z, t_complex c)
{
	int	n;
	int	i;
	int	t;

	t = ((t_fract *)fract)->theme;
	n = ((t_fract *)fract)->max_iteration;
	i = 0;
	while (i < n)
	{
		z = complex_power(z);
		z = complex_add(z, c);
		if (modulus2(z) > 4.)
		{
			return (map_color(t, i, n, ((t_fract *)fract)->zoom));
		}
		i++;
	}
	return (0x00);
}
