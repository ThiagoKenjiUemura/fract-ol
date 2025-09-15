/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:50:37 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 18:21:46 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// void	error_and_exit(char *msg)
// {
// 	write(2, msg, ft_strlen(msg));
// 	write(2, "\n", 1);
// 	exit(1);
// }

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
