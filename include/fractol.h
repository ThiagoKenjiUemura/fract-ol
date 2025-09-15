/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:30 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 10:37:50 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		color;
	int		fractal_type;
}	t_fractol;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	error_and_exit(char *msg);
void	render_mandelbrot(t_fractol *f);
void	render_julia(t_fractol *f);
size_t	ft_strlen(const char *s);
int		close_window(t_fractol *f);
int		key_hook(int keycode, t_fractol *f);

#endif