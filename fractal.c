/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:03:21 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 22:10:21 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract	*new_fract(int iterations, int mod, int antialiasing, enum e_type type)
{
	t_fract	*ret;

	ret = malloc(sizeof(*ret));
	ret->max_iteration = iterations;
	ret->max_mod = mod;
	ret->antialiasing = antialiasing;
	ret->type = type;
	ret->zoom = 1.0;
	ret->theme = 0;
	ret->offset_x = 0.0;
	ret->offset_y = 0.0;
	if (type == Julia)
	{
		ret->constant = new_complex(-1, 0);
		ret->f = &julia;
	}
	if (type == Mandelbrot || type == Burningship)
	{
		ret->constant = new_complex(0, 0);
		ret->f = &mandelbrot;
		if (type == Burningship)
			ret->f = &burningship;
	}
	return (ret);
}

int	change_type(t_fract *fract, enum e_type type)
{
	fract->type = type;
	if (type == Julia)
	{
		fract->constant = new_complex(-1, 0);
		fract->f = &julia;
	}
	if (type == Mandelbrot || type == Burningship)
	{
		fract->constant = new_complex(0, 0);
		fract->f = &mandelbrot;
		if (type == Burningship)
			fract->f = &burningship;
	}
	fract->zoom = 1.0;
	fract->offset_x = 0.0;
	fract->max_iteration = 1;
	fract->offset_y = 0.0;
	return (0);
}

int	get_pixel_color(t_fract fract, t_complex loc, int w, int h)
{
	int	ret;
	int	i;
	int	x;
	int	y;

	x = loc.a;
	y = loc.b;
	x -= w / 2;
	y -= h / 2;
	i = 0;
	ret = 0;
	while (i < fract.antialiasing)
	{
		ret += fract.f(&fract,
				fract.constant,
				new_complex(fract.offset_x + x / (120 * fract.zoom),
					fract.offset_y + y / (120 * fract.zoom))
				);
		i++;
	}
	return (ret / fract.antialiasing);
}

void	draw_fract(t_vars *vars)
{
	t_complex	l;
	t_complex	s;

	l = new_complex(0, 0);
	s = new_complex(vars->w, vars->h);
	while (l.a < s.a)
	{
		l.b = 0;
		while (l.b < s.b)
		{
			mlx_put_pixel(vars->img, l.a, l.b,
				get_pixel_color(*(vars->fract), l, s.a, s.b));
			l.b += 1;
		}
		l.a += 1;
	}	
}
