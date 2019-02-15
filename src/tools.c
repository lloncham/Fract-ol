/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:08:15 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/15 12:16:02 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_mlx	*ptr)
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
