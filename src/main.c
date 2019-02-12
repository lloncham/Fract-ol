#include "../include/fractol.h"

int		deal_key(int key, t_mlx *ptr)
{
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	return (0);
}

void	mlx(t_mlx *ptr)
{
	int bpp;
	int endian;
	int size_l;

	ptr->color = 0xBDF7;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, W, H, "Fractol");
	ptr->img = mlx_new_image(ptr->mlx, W, H);
	ptr->img_data = (int *)mlx_get_data_addr(ptr->img, &bpp, &size_l, &endian);
	draw_fract(ptr);
	mlx_hook(ptr->win, 2, 0, deal_key, ptr);
//	mlx_mouse_hook(ptr->win, mouse_hook, ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	mlx_loop(ptr->mlx);
}

int		main(int ac, char **av)
{
	t_mlx ptr;

	if (ac != 2)
		error("usage : [./fractol] [Mandelbrot/Julia/..]");
	mlx(&ptr);
}
