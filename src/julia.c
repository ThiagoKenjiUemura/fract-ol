/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:23 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/16 18:31:45 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_iterations(double zx, double zy, t_fractol *f)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zx * zx + zy * zy <= 4 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + f->julia_cx;
		zy = 2 * zx * zy + f->julia_cy;
		zx = tmp;
		iter++;
	}
	return (iter);
}

void	render_julia(t_fractol *f)
{
	int		px;
	int		py;
	double	zx;
	double	zy;
	int		iter;
	int		color;

	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			map_pixel(px, py, &zx, &zy, f);
			iter = julia_iterations(zx, zy, f);
			color = color_from_iter(iter, MAX_ITER);
			put_pixel(f, px, py, color);

			px++;
		}
		py++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
