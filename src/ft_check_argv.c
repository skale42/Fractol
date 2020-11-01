/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:25:07 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:25:10 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_check_argv(int c, char *str)
{
	char	*jul;
	char	*mb;

	jul = "julia";
	mb = "mandelbrot";
	if (c != 2)
	{
		write(1, "Choose one fractol: julia mandelbrot bsh\n", 41);
		return (0);
	}
	if (ft_strcmp(str, "bsh") == 0)
		return (3);
	if (ft_strcmp(str, jul) == 0)
		return (2);
	if (ft_strcmp(str, mb) == 0)
		return (1);
	else
	{
		write(1, "Choose one fractol: julia mandelbrot bsh\n", 41);
		return (0);
	}
}
