/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:07:22 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 21:52:54 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(void *fract, t_complex c, t_complex z)
{
	int	n;
	int	i;
	int	t;

	i = 0;
	n = ((t_fract *)fract)->max_iteration;
	t = ((t_fract *)fract)->theme;
	if (z.a == 0 && z.b == 0)
		return (0);
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
	return (0);
}
