/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:26:36 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:26:43 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_key_win(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(mlx->wnd->ptr, mlx->wnd->wnd);
		free(mlx->wnd->img);
		free(mlx->wnd->ptr);
		free(mlx->wnd);
		free(mlx);
		exit(0);
	}
	if (key == PLUSITER)
		mlx->wnd->iter += 10;
	if (key == MINUSITER)
		mlx->wnd->iter -= 10;
	ft_draw_fractal(mlx);
	return (0);
}
