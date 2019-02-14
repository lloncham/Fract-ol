/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:28:13 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/14 17:25:09 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mandelbrot(t_mlx *f, int x, int y)
{
	double tmp;
	int i;
	i = -1;
	init_fract(f, x, y);
	while (++i < f->iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
	    f->z_i = 2 * f->z_i * tmp + f->c_i;
	}
	return (i);
}

int			draw_fract(t_mlx *f)
{
	int x;
	int y;
	int color;
	y = 0;
	while (y < f->size_h)
	{
		x = 0;
		while (x < f->size_w)
		{
			color = init_color(f, mandelbrot(f, x, y));
			ft_put_pixel(f, y, x, color);
			x++;
		}
		y++;
	}
	return (0);
}
