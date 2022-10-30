/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:07:53 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 17:32:40 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_circle(t_data *data, t_complex loc, int radius, int color)
{
	double	i;
	int		x;
	int		y;

	i = 0;
	while (i < 360)
	{
		x = loc.a + cos(i * (M_PI / 180)) * radius;
		y = loc.b + sin(i * (M_PI / 180)) * radius;
		mlx_put_pixel(data, x, y, color);
		color += 0.1;
		i += 0.1;
	}
}

int	handle_exit(t_vars *vars)
{
	free(vars->img);
	free(vars->fract);
	free(vars);
	exit(0);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	t_complex	c;
	enum e_type	type;
	double		zoom;
	double		x;
	double		y;

	x = vars->fract->offset_x;
	y = vars->fract->offset_y;
	zoom = vars->fract->zoom;
	type = vars->fract->type;
	c = vars->fract->constant;
	draw_fract(vars);
	if (type == Julia && zoom == 1 && !(x + y))
		ft_draw_circle(vars->img, new_complex((c.a * zoom * 240 + vars->w) / 2,
				(c.b * zoom * 240 + vars->h) / 2), 5, 0x00fcba03);
	vars->fract->max_iteration += 4;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

t_vars	*new_vars(int w, int h, char *title, t_params params)
{
	t_vars	*vars;

	vars = malloc(sizeof(*vars));
	vars->img = malloc(sizeof(*(vars->img)));
	if (!vars || !vars->img)
	{
		free(vars->img);
		free(vars);
		return (0);
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, w, h, title);
	vars->img->img = mlx_new_image(vars->mlx, w, h);
	vars->img->addr = mlx_get_data_addr(
			vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->line_length,
			&vars->img->endian);
	vars->rendering = 1;
	vars->n = params.n;
	vars->fract = new_fract(20, 4., 1, params.type);
	vars->fract->zoom = 1.0;
	vars->w = w;
	vars->h = h;
	return (vars);
}
