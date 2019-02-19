/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:08:15 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/19 16:19:21 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_mlx *ptr)
{
	bzero(ptr->img_data, ptr->size_w * ptr->size_h * 4);
	return (0);
}

void	ft_put_pixel(t_mlx *p, int y, int x, int color)
{
	if (x < 0 || y < 0 || x >= p->size_w || y >= p->size_h)
		return ;
	p->img_data[y * p->size_w + x] = color;
}

int		ispaire(int nb)
{
	if (nb % 2 == 0)
		return (1);
	return (0);
}

void	reset_all(t_mlx *ptr)
{
	if (ptr->choose == 1)
		*ptr = init_mandelbrot(*ptr);
	if (ptr->choose == 2)
		*ptr = init_julia(*ptr);
	if (ptr->choose == 3)
		*ptr = init_heart(*ptr);
	ptr->color = 0;
}
