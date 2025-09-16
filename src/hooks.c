/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:18:04 by tkenji-u          #+#    #+#             */
/*   Updated: 2025/09/16 18:22:48 by tkenji-u         ###   ########.fr       */
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
