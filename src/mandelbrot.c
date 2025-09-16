/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:34 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/16 18:26:22 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_iterations(double re, double im, int max_iter)
{
	double z_re = 0;
	double z_im = 0;
	double tmp;
	int iter = 0;

	while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + re;
		z_im = 2 * z_re * z_im + im;
		z_re = tmp;
		iter++;
	}
	return iter;
}

void	render_mandelbrot(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	double	re;
	double	im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			map_to_complex(x, y, f, &re, &im);
			iter = mandelbrot_iterations(re, im, MAX_ITER);
			put_pixel(f, x, y, color_from_iter(iter, MAX_ITER));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
