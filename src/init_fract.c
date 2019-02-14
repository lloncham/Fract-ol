/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:59:15 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/14 17:25:06 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mlx		init_mandelbrot(t_mlx ptr)
{
	ptr.choose = 1;
	ptr.x1 = -2.1;
	ptr.x2 = 0.6;
	ptr.y1 = -1.2;
	ptr.y2 = 1.2;
	ptr.zoom = 500;
	ptr.imgx = (ptr.x2 - ptr.x1) * ptr.zoom;
	ptr.imgy = (ptr.y2 - ptr.y1) * ptr.zoom;
	ptr.size_w = ptr.imgx;
	ptr.size_h = ptr.imgy;
	ft_putnbr(ptr.size_h);
	ptr.size_w = ptr.imgx;
	ptr.size_w = ptr.imgx;
	ptr.iter = 150;
	return (ptr);
}

t_mlx		init_julia(t_mlx ptr)
{
	ptr.choose = 2;
	ptr.x1 = -1;
	ptr.x2 = 1;
	ptr.y1 = -1.2;
	ptr.y2 = 1.2;
	ptr.zoom = 200;
	ptr.imgx = (ptr.x2 - ptr.x1) * ptr.zoom;
	ptr.imgy = (ptr.y2 - ptr.y1) * ptr.zoom;
	ptr.size_w = ptr.imgx;
	ptr.size_h = ptr.imgy;
	ptr.iter = 150;
	return (ptr);
}

void		init_fract(t_mlx *f, int x, int y)
{
	if (f->choose == 1)
	{
		f->c_r = (double)x / (double)f->zoom + f->x1;
		f->c_i = (double)y / (double)f->zoom + f->y1;
		f->z_r = 0;
		f->z_i = 0;
	}
	if (f->choose == 2)
	{
		f->c_r = 0.285;
		f->c_i = 0.01;
		f->z_r = (double)x / (double)f->zoom + f->x1;
		f->z_i = (double)y / (double)f->zoom + f->y1;
	}
}
