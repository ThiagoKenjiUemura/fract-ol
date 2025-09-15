/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:20:25 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/15 18:23:39 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// static void	ft_hooks(t_fractol *f)
// {
// 	mlx_key_hook(f->win, key_hook, &f);
// 	mlx_hook(f->win, 17, 0, close_window, &f);
// }

void	init_fract(t_fractol *f)
{
	f->mlx = mlx_init();
	if(!f->mlx)
		ft_clean_exit(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if(!f->win)
		ft_clean_exit(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if(!f->img)
		ft_clean_exit(f);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->end);
	if(!f->img_data)
		ft_clean_exit(f);
}

int	main(void)
{
	t_fractol 	f;
	init_fract(&f);
	mlx_loop(f.mlx);
}
