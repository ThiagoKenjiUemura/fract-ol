/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiagouemura <thiagouemura@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:20:25 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/09/11 16:10:32 by thiagouemur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
    t_fractol f;

    // Define tamanho da janela
    f.width = 800;
    f.height = 600;

    // Inicializa MLX
    f.mlx = mlx_init();
    if (!f.mlx)
        return (1);

    // Cria janela
    f.win = mlx_new_window(f.mlx, f.width, f.height, "Fractol");
    if (!f.win)
        return (1);

    // Loop da MLX (a janela fica aberta)
    mlx_loop(f.mlx);

    return (0);
}
