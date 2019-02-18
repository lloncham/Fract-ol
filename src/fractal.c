/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:28:13 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/15 15:59:56 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mandelbrot(t_mlx *f, int x, int y)
{
	float tmp;
	int i;
	i = -1;
	f->c_r = x / f->zoomx + f->x1;
	f->c_i = y / f->zoomy + f->y1;
	f->z_r = 0;
	f->z_i = 0;
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
	    f->z_i = 2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int		julia(t_mlx *f, int x, int y)
{
	float tmp;
	int i;
	i = -1;
	f->z_r = x / f->zoomx + f->x1;
	f->z_i = y / f->zoomy + f->y1;
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
	    f->z_i = 2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int		third(t_mlx *f, int x, int y)
{
	float tmp;
	int i;
	i = -1;
	f->c_r = 0.0694;
	f->c_i = 0;
//	f->c_r = 0.71;
//	f->c_i = 0.23;
	f->z_r = x / f->zoomx + f->x1;
	f->z_i = y / f->zoomy + f->y1;
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r - f->z_i * f->z_i + f->c_r;
	    f->z_i = 2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int		tricorn(t_mlx *f, int x, int y)
{
	float tmp;
	int i;
	i = -1;
	f->c_r = x / f->zoomx + f->x1;
	f->c_i = y / f->zoomy + f->y1;
	f->z_r = 0;
	f->z_i = 0;
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
	    f->z_i = -2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int			draw_fract(t_mlx *f)
{
	int x;
	int y;
	int color;
	int i;
	y = 0;
	while (y < f->size_h)
	{
		x = 0;
		while (x < f->size_w)
		{
			if (f->choose == 1)
				i = mandelbrot(f, x, y);
			if (f->choose == 2)
				i = julia(f, x, y);
			if (f->choose == 3)
				i = third(f, x, y);
			if (f->choose == 4)
				i = tricorn(f, x, y);
			if (i == f->iter)
				color = (i * 0 / f->iter);
			else
				color = (i * 5 *  65793 +  0xBB0B0B) + f->color;
			ft_put_pixel(f, y, x, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
