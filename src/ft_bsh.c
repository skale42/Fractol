/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:23:48 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:23:51 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_ins2(t_dot dot)
{
	double	lim;

	lim = 2.0;
	if (dot.x < lim && dot.x > -lim && dot.y < lim && dot.y > -lim)
		return (1);
	return (0);
}

int		ft_bsh(t_dot dot, t_dot jconst, int wnditer)
{
	t_dot	cp;
	double	tmp;
	int		iter;

	iter = 0;
	cp.x = dot.x;
	cp.y = dot.y;
	while (iter < wnditer && ft_ins2(cp))
	{
		tmp = cp.x;
		cp.x = cp.x * cp.x * cp.x - 3 * cp.x * cp.y * cp.y + jconst.x;
		cp.y = 3 * tmp * tmp * cp.y - cp.y * cp.y * cp.y + jconst.y;
		iter++;
	}
	if (ft_ins2(cp))
		return (BACKGROUND);
	else if (iter > 0 && iter < 50)
		return (rgb_to_int(10, 0 + (2 * iter), 0 + 3 * iter));
	else
		return (rgb_to_int(50 + (1 * iter), 0 + (2 * iter), 50 + 2 * iter));
}
