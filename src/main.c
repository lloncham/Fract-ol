/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:47 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/15 16:00:47 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		deal_key(int key, t_mlx *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	clear_img(ptr);
	if (key == 126)
		ptr->y1 += 0.025;
	if (key == 125)
		ptr->y1 -= 0.025;
	if (key == 123)
		ptr->x1 += 0.025;
	if (key == 124)
		ptr->x1 -= 0.025;
	if (key == 49)
		ptr->color += 10;
	if (key == 34)
		ptr->iter -= 5;
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	draw_fract(ptr);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *ptr)
{
	ft_putnbr(button);
	ft_putchar('\n');
	clear_img(ptr);
	x -= ptr->size_w/2;
	y -= ptr->size_h/2;
	if (button == 4)
	{
		ptr->zoomy = (ptr->zoomy + (ptr->y2 - ptr->y1) / ptr->size_h) * 1.1;
		ptr->zoomx = (ptr->zoomx + (ptr->x2 - ptr->x1) / ptr->size_w) * 1.1;
		ptr->iter += 1;
		ptr->x1 += x / ptr->zoomx;
		ptr->x2 += x / ptr->zoomx;
		ptr->y1 += y / ptr->zoomx;
		ptr->y2 += y / ptr->zoomx;
		
	}
	if (button == 5)
	{
		ptr->zoomy = (ptr->zoomy + (ptr->y2 - ptr->y1) / ptr->size_h) / 1.1;
		ptr->zoomx = (ptr->zoomx + (ptr->x2 - ptr->x1) / ptr->size_w) / 1.1;
		ptr->x1 += x / ptr->zoomx;
		ptr->x2 += x / ptr->zoomx;
		ptr->y1 += y / ptr->zoomx;
		ptr->y2 += y / ptr->zoomx;

	}
	draw_fract(ptr);
	return (0);
}

int	motion_hook(int x, int y, t_mlx *ptr)
{
	float dx;
	float dy;
	if (x < ptr->size_w && y < ptr->size_h && x > 0 && y > 0)
	{	
		dx = ((float)x - ((float)ptr->size_w) / 2) / (ptr->size_w / 2);
		dy = ((float)y - ((float)ptr->size_h) / 2) / (ptr->size_h / 2);
		printf("x = %f ; y = %f \n", dx , dy);
	}
	return (0);
}

void	mlx(t_mlx *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->color = 0;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->size_w, ptr->size_h, "Fractol");
	ptr->img = mlx_new_image(ptr->mlx, ptr->size_w, ptr->size_h);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	draw_fract(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_hook(ptr->win, 6, 0, motion_hook, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_loop(ptr->mlx);
}

int		main(int ac, char **av)
{
	t_mlx ptr;

	if (ac != 2)
		error("usage : [./fractol] [Mandelbrot/Julia/..]");
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ptr = init_mandelbrot(ptr);
	if (ft_strcmp(av[1], "Julia") == 0)
		ptr = init_julia(ptr);
	mlx(&ptr);
}
