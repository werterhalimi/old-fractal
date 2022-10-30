/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:05:06 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 03:16:42 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	new_complex(double a, double b)
{
	t_complex	ret;

	ret.a = a;
	ret.b = b;
	return (ret);
}

t_complex	complex_power(t_complex z)
{
	t_complex	ret;

	ret = new_complex(z.a * z.a - z.b * z.b, 2.0 * z.a * z.b);
	return (ret);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	return (new_complex(a.a + b.a, a.b + b.b));
}

double	modulus(t_complex z)
{
	return (sqrt(z.a * z.a + z.b * z.b));
}

double	modulus2(t_complex z)
{
	return (z.a * z.a + z.b * z.b);
}
