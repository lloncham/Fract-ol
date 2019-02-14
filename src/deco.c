#include "../include/fractol.h"

void	put_info(t_mlx *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, ptr->size_w / 2 - 1.5, 10, 0xFFFFFF, "Fractol");
	mlx_string_put(ptr->mlx, ptr->win, 20, 45, 0xFFFFFF, "MENU");
}
