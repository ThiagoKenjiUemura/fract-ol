/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:37 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/16 18:36:46 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	get_decimal_part(const char *str);

void	error_and_exit(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

int	ft_clean_exit(t_fractol *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
}
static double	get_decimal_part(const char *str)
{
	double dec = 0.1;
	double res = 0;

	while (*str >= '0' && *str <= '9')
	{
		res += (*str - '0') * dec;
		dec *= 0.1;
		str++;
	}
	return (res);
}

double	ft_atof(const char *str)
{
	double	res;
	int		neg;

	res = 0;
	neg = 0;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		res += get_decimal_part(str);
	}
	if (neg)
		res = -res;
	return (res);
}

