#include "../include/fractol.h"

void	put_info(t_mlx *ptr)
{
	if (ptr->choose == 1)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w - 110, ptr->size_h - 30, 0xffffff, "Mandelbrot");
	if (ptr->choose == 2)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w - 60, ptr->size_h - 30, 0xffffff, "Julia");
	if (ptr->choose == 3)
		mlx_string_put(ptr->mlx, ptr->win, ptr->size_w - 120, ptr->size_h - 30, 0xffffff, "fractol");
	mlx_string_put(ptr->mlx, ptr->win, 10, 10, 0xFFFFFF, "MENU");
	mlx_string_put(ptr->mlx, ptr->win, 10, 40, 0xFFFFFF, "Iteration : I, P");
	mlx_string_put(ptr->mlx, ptr->win, 10, 60, 0xFFFFFF, "Color : space");
	mlx_string_put(ptr->mlx, ptr->win, 10, 80, 0xFFFFFF, "Move : v, ^, >, <");
	mlx_string_put(ptr->mlx, ptr->win, 10, 100, 0xFFFFFF, "Reset : R");
	mlx_string_put(ptr->mlx, ptr->win, 10, 120, 0xFFFFFF, "Zoom : mouse scrool");
	mlx_string_put(ptr->mlx, ptr->win, 10, ptr->size_h - 30, 0xFFFFFF, "iteration : ");
	mlx_string_put(ptr->mlx, ptr->win, 125, ptr->size_h - 29, 0xFFFFFF, ft_itoa(ptr->iter));
}
