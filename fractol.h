/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skale <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:07:21 by skale             #+#    #+#             */
/*   Updated: 2020/08/07 19:22:08 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <zconf.h>
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include "keys.h"
# define WX 800
# define WY 400
# define BACKGROUND 0x222222
# define PI	3.14159265358979323846
# define INSIDE(x, y) ((x > 0 && y > 0 && x < WX && y < WY) ? 1 : 0)
# define NUM_THREAD 8

typedef struct		s_dot
{
	double			x;
	double			y;
}					t_dot;

typedef struct		s_wnd
{
	void			*ptr;
	void			*wnd;
	void			*img;
	char			*data_addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	double			len_x;
	double			len_y;
	double			stepx;
	double			stepy;
	double			startx;
	double			finishx;
	double			starty;
	double			finishy;
	int				sty;
	int				endy;
	t_dot			juli_const;
	int				iter;
	int				type;
}					t_wnd;

typedef struct		s_mlx
{
	t_wnd			*wnd;
}					t_mlx;

int					ft_mouse_move(int x, int y, t_mlx *mlx);
int					ft_mouse_pressed(int buttom, int x, int y, t_mlx *mlx);
int					rgb_to_int(int red, int green, int blue);
void				ft_draw_fractal(t_mlx *mlx);
int					ft_check_argv(int c, char *str);
int					ft_key_win(int key, t_mlx *mlx);
void				ft_catch_order(t_mlx *mlx);
t_wnd				*ft_init_window(int argc, char *ch);
int					ft_julia(t_dot dot, t_dot jconst, int wnditer);
int					ft_mb(t_dot dot, int wnditer);
int					ft_bsh(t_dot dot, t_dot jconst, int wnditer);

#endif
