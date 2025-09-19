/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:34 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/19 15:13:57 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_iterations(double re, double im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + re;
		z_im = 2 * z_re * z_im + im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

void	render_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) * (4.0 / WIDTH) / f->zoom + f->offset_x;
			c.im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) / f->zoom + f->offset_y;
			iter = mandelbrot_iterations(c.re, c.im, f->max_iter);
			put_pixel(f, x, y, color_from_iter(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
