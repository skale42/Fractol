/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:24:11 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:24:21 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			ft_close(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	write(1, "you destroyed fractol \n", 22);
	mlx_destroy_window(mlx->wnd->ptr, mlx->wnd->wnd);
	free(mlx->wnd->img);
	free(mlx->wnd->ptr);
	free(mlx->wnd);
	free(mlx);
	(void)param;
	exit(0);
}

void		ft_catch_order(t_mlx *mlx)
{
	mlx_hook(mlx->wnd->wnd, 2, (1Lu << 0u), ft_key_win, mlx);
	mlx_hook(mlx->wnd->wnd, 17, (1Lu << 17u), ft_close, mlx);
	mlx_hook(mlx->wnd->wnd, 4, (1Lu << 2u), ft_mouse_pressed, mlx);
	if (mlx->wnd->type == 2 || mlx->wnd->type == 3)
		mlx_hook(mlx->wnd->wnd, 6, (1Lu << 13u), ft_mouse_move, mlx);
}
