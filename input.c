/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:59:26 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 22:09:44 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	double	zoom;
	double	*offset_y;
	double	*offset_x;

	offset_x = &vars->fract->offset_x;
	offset_y = &vars->fract->offset_y;
	zoom = vars->fract->zoom;
	if (!vars->rendering)
	{
		*offset_x += (vars->x - (double) x) / 1920.0 / zoom;
		*offset_y += (vars->y - (double) y) / 1080.0 / zoom;
		vars->fract->max_iteration = fmin(vars->n, fmax(50, zoom / 2));
	}
	return (0);
}

int	handle_roll(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		vars->fract->zoom *= 1.10;
	if (button == 5)
		vars->fract->zoom *= 0.90;
	vars->fract->offset_x += (x - vars->w / 2) / (120 * 3 * vars->fract->zoom);
	vars->fract->offset_y += (y - vars->h / 2) / (120 * 3 * vars->fract->zoom);
	vars->fract->max_iteration = fmin(fmax(80, vars->fract->zoom / 2), vars->n);
	if (vars->fract->zoom < 1)
		vars->fract->zoom = 1;
	return (0);
}

int	mouse_down(int button, int x, int y, t_vars *vars)
{
	t_complex	*c;
	double		zoom;

	zoom = vars->fract->zoom;
	c = &vars->fract->constant;
	if (button == 4 || button == 5)
		return (handle_roll(button, x, y, vars));
	if (button == 2 && vars->fract->type == Julia && zoom == 1)
	{
		*c = new_complex((x - vars->w / 2.0) / 120.0 * zoom,
				(y - vars->h / 2.0) / 120.0 * zoom);
		vars->fract->max_iteration = 1;
		return (0);
	}
	if (y < 0)
		return (0);
	vars->x = x;
	vars->y = y;
	vars->rendering = 0;
	return (0);
}

int	mouse_up(int button, int x, int y, t_vars *vars)
{
	(void )x;
	(void) button;
	if (y > 0)
		vars->rendering = 1;
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	if (keycode == 11)
		return (change_type(vars->fract, Burningship));
	if (keycode == 46)
		return (change_type(vars->fract, Mandelbrot));
	if (keycode == 38)
		return (change_type(vars->fract, Julia));
	if (keycode >= 18 && keycode <= 26)
		vars->fract->theme = keycode - 18;
	if (keycode == 53)
		return (handle_exit(vars));
	if (keycode == 125)
		vars->fract->offset_y += 0.1;
	if (keycode == 126)
		vars->fract->offset_y -= 0.1;
	if (keycode == 123)
		vars->fract->offset_x -= 0.1;
	if (keycode == 124)
		vars->fract->offset_x += 0.1;
	vars->fract->max_iteration = fmin(vars->n, fmax(50, vars->fract->zoom / 2));
	return (0);
}
