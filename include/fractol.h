#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

# define H 1200
# define W 2000

typedef	struct		s_mlx
{
	int				*mlx;
	int				*win;
	int				*img;
	int				*img_data;
	int				color;
	float			zoom;
	float			cr;
	float			ci;
	float			zr;
	float			zi;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	int				iter;
}					t_mlx;

void				error(char *str);
int					clear_img(t_mlx *ptr);
void				ft_put_pixel(t_mlx *ptr, int y, int x, int color);
int					draw_fract(t_mlx *f);
int					init_color(t_mlx *f, int i);

#endif
