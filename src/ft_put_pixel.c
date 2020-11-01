/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:28:09 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:28:12 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			rgb_to_int(int red, int green, int blue)
{
	int		r;
	int		g;
	int		b;

	r = red & 0xFF;
	g = green & 0xFF;
	b = blue & 0xFF;
	return (r << 16 | g << 8 | b);
}

void		ft_put_pixel(int x, int y, int color, t_wnd *wnd)
{
	int i;

	if (x >= 0 && x < WX && y >= 0 && y < WY)
	{
		i = x * wnd->bit_per_pixel / 8 + wnd->size_line * y;
		wnd->data_addr[i + 0] = (color) & 0xFF;
		wnd->data_addr[i + 1] = (color >> 8) & 0xFF;
		wnd->data_addr[i + 2] = (color >> 16) & 0xFF;
		wnd->data_addr[i + 3] = 0;
	}
}
