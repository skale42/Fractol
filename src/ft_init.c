/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:26:13 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:26:17 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_set_wnd(t_wnd *wnd)
{
	wnd->startx = -2;
	wnd->finishx = 2;
	wnd->starty = 1;
	wnd->finishy = -1;
	wnd->len_x = wnd->finishx - wnd->startx;
	wnd->len_y = wnd->starty - wnd->finishy;
	wnd->juli_const.x = -0.70176;
	wnd->juli_const.y = -0.3842;
	wnd->iter = 100;
}

t_wnd		*ft_init_window(int argc, char *ch)
{
	t_wnd	*wnd;

	if (!(wnd = (t_wnd*)ft_memalloc(sizeof(t_wnd))))
		exit(2);
	wnd->type = ft_check_argv(argc, ch);
	if (wnd->type == 0)
		return (NULL);
	if (!(wnd->ptr = mlx_init()))
		exit(1);
	if (!(wnd->wnd = mlx_new_window(wnd->ptr, WX, WY, "MyFractol")))
		exit(1);
	if (!(wnd->img = mlx_new_image(wnd->ptr, WX, WY)))
		exit(1);
	wnd->data_addr = mlx_get_data_addr(wnd->img, &wnd->bit_per_pixel, \
			&wnd->size_line, &wnd->endian);
	ft_set_wnd(wnd);
	return (wnd);
}
