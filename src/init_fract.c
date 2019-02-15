/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:59:15 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/15 15:51:33 by lloncham         ###   ########.fr       */
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
	ptr.zoomx = 200;
	ptr.zoomy = 200;
	ptr.imgx = (ptr.x2 - ptr.x1) * ptr.zoomx;
	ptr.imgy = (ptr.y2 - ptr.y1) * ptr.zoomy;
	ptr.size_w = ptr.imgx;
	ptr.size_h = ptr.imgy;
	ptr.iter = 50;
	return (ptr);
}

t_mlx		init_julia(t_mlx ptr)
{
	ptr.choose = 2;
	ptr.x1 = -1;
	ptr.x2 = 1;
	ptr.y1 = -1.2;
	ptr.y2 = 1.2;
	ptr.zoomx = 200;
	ptr.zoomy = 200;
	ptr.imgx = (ptr.x2 - ptr.x1) * ptr.zoomx;
	ptr.imgy = (ptr.y2 - ptr.y1) * ptr.zoomy;
	ptr.size_w = ptr.imgx;
	ptr.size_h = ptr.imgy;
	ptr.iter = 50;
	return (ptr);
}
