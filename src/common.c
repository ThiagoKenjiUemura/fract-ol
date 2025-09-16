/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:19:03 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/09/16 18:25:28 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char *dst;

	dst = f->img_data + (y * f->size_line + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	map_to_complex(int x, int y, t_fractol *f, double *re, double *im)
{
	*re = (x - WIDTH / 2.0) * (4.0 / WIDTH) / f->zoom + f->offset_x;
	*im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) / f->zoom + f->offset_y;
}


int	color_from_iter(int iter)
{
	if (iter == MAX_ITER)
		return 0x000000;
	return 0x00FF00 * iter / MAX_ITER;
}
