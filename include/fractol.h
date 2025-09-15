/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:25:30 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 08:56:59 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>

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

#endif