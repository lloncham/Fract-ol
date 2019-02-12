#include "../include/fractol.h"

void		init_mandelbrot(t_mlx *f)
{
	f->zoom = 250;
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
}

void		mandelbrot(t_mlx *f, int x, int y)
{
	int i;
	int tmp;
	
	f->zr = 0;
	f->zi = 0;
	f->cr = x / f->zoom + f->x1;
	f->ci = y / f->zoom + f->y1;
	i = 0;
	while (i < 16 && (f->zr * f->zr + f->zi * f->zi) < 4)
	{
		tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * tmp * f->zi + f->ci;
		i++;
	}
	if (i == 16)
		ft_put_pixel(f, y, x);

}

int			draw_fract(t_mlx *f)
{
	int x;
	int y;

	y = 0;
	init_mandelbrot(f);
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			mandelbrot(f, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
