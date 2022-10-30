/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalimi <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:02:46 by shalimi           #+#    #+#             */
/*   Updated: 2022/10/30 22:13:57 by shalimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	handle_wrong_params(void)
{
	ft_putendl_fd("Wrong parameter.", 1);
	ft_putendl_fd("Try julia, mandelbrot or burningship", 1);
	exit(1);
}

t_params	parse_input(int argc, char **argv)
{
	t_params	ret;

	ret.n = 100;
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], J, ft_strlen(J)) == 0)
			ret.type = Julia;
		else if (ft_strncmp(argv[1], M, ft_strlen(M)) == 0)
			ret.type = Mandelbrot;
		else if (ft_strncmp(argv[1], B, ft_strlen(B)) == 0)
			ret.type = Burningship;
		else
			handle_wrong_params();
		if (argc >= 3)
		{
			if (ft_atoi(argv[2]))
				ret.n = ft_atoi(argv[2]);
			else
				handle_wrong_params();
		}
	}
	else
		handle_wrong_params();
	return (ret);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	char		line[2];
	int			fd;
	int			i;

	line[1] = 0;
	vars = new_vars(600, 600, "Hell world", parse_input(argc, argv));
	fd = open("welcome.c", O_RDONLY);
	i = read(fd, line, 1);
	while (i > 0)
	{
		ft_putstr_fd(line, 1);
		i = read(fd, line, 1);
	}
	close(fd);
	mlx_hook(vars->win, ON_KEYUP, 0, key_up, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, handle_exit, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 0, mouse_down, vars);
	mlx_hook(vars->win, ON_MOUSEUP, 0, mouse_up, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mouse_move, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}
