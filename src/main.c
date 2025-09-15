/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:20:25 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 10:39:35 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
		error_and_exit("Usage: ./fractol mandelbrot | julia");
	f.width = 800;
	f.height = 600;
	f.zoom = 1.0;
	f.offset_x = 0;
	f.offset_y = 0;
	f.max_iter = 50;
	f.color = 0xFFFFFF;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.width, f.height, "fract-ol");
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	if (!f.mlx || !f.win)
		error_and_exit("Error initializing MLX");
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		render_mandelbrot(&f);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		render_julia(&f);
	else
		error_and_exit("Invalid fractal name");
	mlx_loop(f.mlx);
	return (0);
}
