/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:27:06 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:27:08 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_dot	ft_add(t_dot c1, t_dot c2)
{
	return ((t_dot){c1.x + c2.x, c1.y + c2.y});
}

t_dot	ft_quadro(t_dot c1)
{
	t_dot res;

	res.x = c1.x * c1.x - c1.y * c1.y;
	res.y = 2 * c1.x * c1.y;
	return (res);
}

int		ft_inside(t_dot dot)
{
	double lim;

	lim = 2.0;
	if (dot.x < lim && dot.x > -lim && dot.y < lim && dot.y > -lim)
		return (1);
	return (0);
}

int		ft_mb(t_dot dot, int wnditer)
{
	t_dot	cp;
	int		iter;

	iter = 0;
	cp.x = 0;
	cp.y = 0;
	while (iter < wnditer && ft_inside(cp))
	{
		cp = ft_add(ft_quadro(cp), dot);
		iter++;
	}
	if (ft_inside(cp))
		return (BACKGROUND);
	else if (iter > 0 && iter < 50)
		return (rgb_to_int(10, 0 + (2 * iter), 0 + 3 * iter));
	else
		return (rgb_to_int(50 + (1 * iter), 0 + (2 * iter), 50 + 2 * iter));
}
