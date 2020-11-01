/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:08:01 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:21:11 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->wnd = ft_init_window(argc, argv[1])))
		return (0);
	ft_catch_order(mlx);
	ft_draw_fractal(mlx);
	mlx_loop(mlx->wnd->ptr);
	return (0);
}
