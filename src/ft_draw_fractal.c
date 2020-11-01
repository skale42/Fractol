/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:25:45 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:25:54 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_launch(int i, double x, double y, t_wnd *wnd)
{
	int		*image;

	image = (int *)(wnd->data_addr);
	if (wnd->type == 1)
		image[i + wnd->sty * WX] = ft_mb((t_dot){x, y}, wnd->iter);
	if (wnd->type == 2)
		image[i + wnd->sty * WX] = ft_julia((t_dot){x, y}, wnd->juli_const, \
									wnd->iter);
	if (wnd->type == 3)
		image[i + wnd->sty * WX] = ft_bsh((t_dot){x, y}, wnd->juli_const, \
									wnd->iter);
}

void		*thread_function(void *func)
{
	int		i;
	double	x;
	double	y;
	t_wnd	*wnd;

	wnd = (t_wnd *)func;
	wnd->stepx = wnd->len_x / WX;
	wnd->stepy = wnd->len_y / WY;
	y = wnd->starty - wnd->sty * wnd->stepy;
	while (wnd->sty < wnd->endy)
	{
		i = 0;
		x = wnd->startx;
		while (i < WX)
		{
			x = x + wnd->stepx;
			ft_launch(i, x, y, wnd);
			i++;
		}
		y = y - wnd->stepy;
		wnd->sty++;
	}
	return (NULL);
}

void		ft_multi_thread(t_wnd *scene)
{
	pthread_t	id[NUM_THREAD];
	t_wnd		data[NUM_THREAD];
	int			n;

	n = 0;
	while (n < NUM_THREAD)
	{
		data[n] = *scene;
		data[n].sty = n * WY / NUM_THREAD;
		data[n].endy = (n + 1) * WY / NUM_THREAD;
		pthread_create(&id[n], NULL, thread_function, &data[n]);
		n += 1;
	}
	n = 0;
	while (n < NUM_THREAD)
	{
		pthread_join(id[n], NULL);
		n += 1;
	}
}

void		ft_draw_fractal(t_mlx *mlx)
{
	ft_multi_thread(mlx->wnd);
	mlx_put_image_to_window(mlx->wnd->ptr, mlx->wnd->wnd, mlx->wnd->img, 0, 0);
}
