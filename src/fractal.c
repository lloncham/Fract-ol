/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:28:13 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/19 17:33:45 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mandelbrot_julia_tricorn(t_mlx *f, int x, int y)
{
	float	tmp;
	int		i;

	i = -1;
	init(f, x, y);
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = (2 * f->nb) * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int		heart(t_mlx *f, int x, int y)
{
	float	tmp;
	int		i;

	i = -1;
	init(f, x, y);
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int		burningship(t_mlx *f, int x, int y)
{
	float	tmp;
	int		i;

	i = -1;
	init(f, x, y);
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = fabs(f->z_r * f->z_r - f->z_i * f->z_i + f->c_r);
		f->z_i = fabs(2 * f->z_i * tmp + f->c_i);
	}
	return (i);
}

int		init_color(t_mlx *f, int i)
{
	int color;

	if (i == f->iter)
		color = (i * 0 / f->iter);
	else
		color = (i * 5 * 65793 + 0xBB0B0B) + f->color;
	return (color);
}

int		draw_fract(t_mlx *f)
{
	int		x;
	int		y;
	int		color;
	int		i;

	y = 0;
	while (y < f->size_h)
	{
		x = 0;
		while (x < f->size_w)
		{
			if (f->choose == 1 || f->choose == 2 || f->choose == 4)
				i = mandelbrot_julia_tricorn(f, x, y);
			if (f->choose == 3)
				i = heart(f, x, y);
			if (f->choose == 5)
				i = burningship(f, x, y);
			color = init_color(f, i);
			ft_put_pixel(f, y, x, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
