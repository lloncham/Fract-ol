/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:47 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/19 17:05:15 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		deal_key(int key, t_mlx *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	clear_img(ptr);
	if (key == 49)
		ptr->stop += 1;
	if (key == 126 || key == 125)
		(key == 126) ? (ptr->y1 -= 0.02) : (ptr->y1 += 0.02);
	if (key == 123 || key == 124)
		(key == 123) ? (ptr->x1 -= 0.02) : (ptr->x1 += 0.02);
	if (key == 8)
		ptr->color += 10;
	if (key == 78 || key == 69)
		(key == 78) ? (ptr->iter -= 5) : (ptr->iter += 5);
	if (key == 15)
		reset_all(ptr);
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	draw_fract(ptr);
	put_info(ptr);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *ptr)
{
	clear_img(ptr);
	x -= ptr->size_w / 2;
	y -= ptr->size_h / 2;
	if (button == 4)
	{
		ptr->zoomy = (ptr->zoomy + (ptr->y2 - ptr->y1) / ptr->size_h) * 1.2;
		ptr->zoomx = (ptr->zoomx + (ptr->x2 - ptr->x1) / ptr->size_w) * 1.2;
		ptr->iter += 1;
	}
	if (button == 5)
	{
		ptr->zoomy = (ptr->zoomy + (ptr->y2 - ptr->y1) / ptr->size_h) / 1.2;
		ptr->zoomx = (ptr->zoomx + (ptr->x2 - ptr->x1) / ptr->size_w) / 1.2;
	}
	ptr->x1 += x / ptr->zoomx;
	ptr->x2 = x / ptr->zoomx + ptr->x1;
	ptr->y1 += y / ptr->zoomx;
	ptr->y2 = y / ptr->zoomx + ptr->y1;
	draw_fract(ptr);
	put_info(ptr);
	return (0);
}

int		motion_hook(int x, int y, t_mlx *ptr)
{
	float dx;
	float dy;

	if (x < ptr->size_w && y < ptr->size_h && x > 0
		&& y > 0 && ispaire(ptr->stop) == 1)
	{
		dx = ((float)x - ptr->imgx / 2) / (ptr->imgy / 2);
		dy = ((float)y - ptr->imgx / 2) / (ptr->imgy / 2);
		ptr->c_r = dx;
		ptr->c_i = dy;
		draw_fract(ptr);
		put_info(ptr);
	}
	return (0);
}

void	mlx(t_mlx *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->stop = 2;
	ptr->color = 0;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->size_w, ptr->size_h, "Fractol");
	ptr->img = mlx_new_image(ptr->mlx, ptr->size_w, ptr->size_h);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	draw_fract(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_hook(ptr->win, 6, 0, motion_hook, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	put_info(ptr);
	mlx_loop(ptr->mlx);
}

int		main(int ac, char **av)
{
	t_mlx ptr;

	if (ac != 2)
		usage();
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ptr = init_mandelbrot(ptr);
	else if (ft_strcmp(av[1], "Julia") == 0)
		ptr = init_julia(ptr);
	else if (ft_strcmp(av[1], "Heart") == 0)
		ptr = init_heart(ptr);
	else if (ft_strcmp(av[1], "Tricorn") == 0)
		ptr = init_tricorn(ptr);
	else if (ft_strcmp(av[1], "Burningship") == 0)
		ptr = init_burningship(ptr);
	else
		usage();
	mlx(&ptr);
}
