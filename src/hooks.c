/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:04 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/09/19 15:38:58 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 65307)
	{
		ft_clean_exit(f);
	}
	return (0);
}

int	close_window(t_fractol *f)
{
	ft_clean_exit(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	t_complex	pos;
	double		new_zoom;

	map_pixel_to_complex(x, y, f, &pos);
	if (button == 4)
		new_zoom = f->zoom * 1.1;
	else if (button == 5)
		new_zoom = f->zoom / 1.1;
	else
		return (0);
	f->offset_x = pos.re - (x - WIDTH / 2.0) / (0.5 * WIDTH * new_zoom);
	f->offset_y = pos.im - (y - HEIGHT / 2.0) / (0.5 * HEIGHT * new_zoom);
	f->zoom = new_zoom;
	if (f->fractal_type == 0)
		render_mandelbrot(f);
	else
		render_julia(f);
	return (0);
}
