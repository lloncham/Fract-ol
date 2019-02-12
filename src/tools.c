#include "../include/fractol.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_mlx	*ptr)
{
	bzero(ptr->img_data, W * H * 4);
	return (0);
}

void	ft_put_pixel(t_mlx *p, int y, int x)
{
	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	p->img_data[y * W + x] = p->color;
}
