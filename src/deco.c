/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deco.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:38:49 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/19 17:53:42 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_info(t_mlx *ptr)
{
	if (ptr->choose == 1)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w
				- 110, ptr->size_h - 30, 0xffffff, "MANDELBROT");
	if (ptr->choose == 2)
	{
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w
				- 60, ptr->size_h - 30, 0xffffff, "JULIA");
		mlx_string_put(ptr->mlx, ptr->win, 10, 140,
				0xffffff, "Stop / Play : space");
	}
	if (ptr->choose == 3)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w
				- 60, ptr->size_h - 30, 0xffffff, "HEART");
	if (ptr->choose == 4)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w
				- 90, ptr->size_h - 30, 0xffffff, "TRICORN");
	if (ptr->choose == 5)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w
				- 120, ptr->size_h - 30, 0xffffff, "BURNINGSHIP");
	mlx_string_put(ptr->mlx, ptr->win, 10, 10, 0xFFFFFF, "MENU");
	mlx_string_put(ptr->mlx, ptr->win, 10, 40, 0xFFFFFF, "Iteration : +, -");
	mlx_string_put(ptr->mlx, ptr->win, 10, 60, 0xFFFFFF, "Color : C");
	mlx_string_put(ptr->mlx, ptr->win, 10, 80, 0xFFFFFF, "Move : v, ^, >, <");
	mlx_string_put(ptr->mlx, ptr->win, 10, 100, 0xFFFFFF, "Reset : R");
	mlx_string_put(ptr->mlx, ptr->win, 10, 120, 0xFFFFFF, "Zoom : scrool");
}

void	usage(void)
{
	ft_putendl("usage : [./fractol] [Fractale name]");
	ft_putendl(" ");
	ft_putendl("Fractale name :");
	ft_putendl("	-Mandelbrot");
	ft_putendl("	-Julia");
	ft_putendl("	-Heart");
	ft_putendl("	-Tricorn");
	error("	-Burningship");
}
