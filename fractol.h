/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:09:20 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/31 03:15:41 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define M "mandelbrot"
# define J "julia"
# define B "burningship"
# include "mlx.h"
# include <math.h>
# include "libft/libft.h"
# include "get_next_line.h"

enum e_type{
	Julia,
	Mandelbrot,
	Burningship
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_params
{
	int			n;
	enum e_type	type;
}	t_params;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

typedef struct s_fract
{
	int			max_iteration;
	int			max_mod;
	int			theme;
	int			antialiasing;
	enum e_type	type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	t_complex	constant;
	t_complex	c;
	int			(*f)(void *fract, t_complex t, t_complex c);
}	t_fract;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_fract		*fract;
	t_data		*img;
	int			h;
	int			w;
	int			x;
	int			y;
	int			n;
	int			rendering;
}	t_vars;

int			mandelbrot(void *f, t_complex v, t_complex c);
t_complex	new_complex(double x, double y);
t_fract		*new_fract(int iterations, int mod, int a, enum e_type type);
t_complex	new_complex(double a, double b);
void		mlx_put_pixel(t_data *data, int x, int y, int color);
int			mandelbrot(void *fract, t_complex z, t_complex c);
int			julia(void *fract, t_complex c, t_complex z);
double		modulus2(t_complex z);
double		modulus(t_complex z);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_power(t_complex z);
int			get_pixel_color(t_fract fract, t_complex loc, int w, int h);
int			create_trgb(int t, int r, int g, int b);
int			change_type(t_fract *f, enum e_type type);
int			mouse_move(int x, int y, t_vars *vars);
int			mouse_down(int button, int x, int y, t_vars *vars);
int			mouse_up(int button, int x, int y, t_vars *vars);
int			key_up(int key, t_vars *vars);
int			handle_exit(t_vars *vars);
int			handle_exit(t_vars *vars);
int			render_next_frame(t_vars *vars);
int			map_color(int theme, int iter, int n, double zoom);
void		ft_draw_circle(t_data *data, t_complex c, int radius, int color);
void		mlx_put_pixel(t_data *data, int x, int y, int color);
void		draw_fract(t_vars *vars);
t_vars		*new_vars(int w, int h, char *title, t_params params);
int			burningship(void *fract, t_complex z, t_complex c);
#endif
