/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:30:47 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/14 17:25:03 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		deal_key(int key, t_mlx *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	clear_img(ptr);
	if (key == 125)
		ptr->iter += 10;
	if (key == 126)
		ptr->iter -= 10;
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	draw_fract(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_mlx *ptr)
{
	ft_putnbr(button);
	ft_putchar('\n');
	clear_img(ptr);
	if (button == 1)
	{
		x = ptr->size_w/2;
		y = ptr->size_h/2;
		ptr->x1 = x / ptr->zoom - ptr->x1;
		ptr->x2 = x / ptr->zoom + ptr->x2;
		ptr->y1 = x / ptr->zoom - ptr->y1;
		ptr->y2 = y / ptr->zoom + ptr->y2;
		ptr->zoom += 10;
	}
	if (button == 2)
	{
		ptr->zoom -= 10;
	}
	draw_fract(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}

void	mlx(t_mlx *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->color = 0xBDF7;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->size_w, ptr->size_h, "Fractol");
	ptr->img = mlx_new_image(ptr->mlx, ptr->size_w, ptr->size_h);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	draw_fract(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
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
