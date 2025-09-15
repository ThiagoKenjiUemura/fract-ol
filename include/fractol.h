/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:30 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 18:21:16 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 50

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_data;
	int		bpp;
	int		size_line;
	int 	end;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		color;
	int		fractal_type;
}	t_fractol;


int		ft_strncmp(const char *s1, const char *s2, size_t n);
// size_t	ft_strlen(const char *s);
// void	init_fract(t_fractol *f);
// void	error_and_exit(char *msg);
// void	render_mandelbrot(t_fractol *f);
// void	render_julia(t_fractol *f, double real, double imag);
// int		close_window(t_fractol *f);
// int		key_hook(int keycode, t_fractol *f);
// double	ft_atof(const char *str);
int		ft_clean_exit(t_fractol *f);

#endif