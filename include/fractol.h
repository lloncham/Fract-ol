/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:13:06 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/20 15:46:21 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef	struct		s_mlx
{
	int				*mlx;
	int				*win;
	int				*img;
	int				*img_data;
	int				color;
	int				stop;
	float			zoomy;
	float			zoomx;
	float			iter;
	int				choose;
	float			imgx;
	float			imgy;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			nb;
	int				size_h;
	int				size_w;
}					t_mlx;

void				put_info(t_mlx *ptr);
void				error(char *str);
int					clear_img(t_mlx *ptr);
void				ft_put_pixel(t_mlx *ptr, int y, int x, int color);
int					draw_fract(t_mlx *f);
void				init(t_mlx *f, int x, int y);
void				init_fract(t_mlx *f, int x, int y);
t_mlx				init_mandelbrot(t_mlx ptr);
t_mlx				init_julia(t_mlx ptr);
t_mlx				init_heart(t_mlx ptr);
t_mlx				init_tricorn(t_mlx ptr);
t_mlx				init_burningship(t_mlx ptr);
int					ispaire(int nb);
void				reset_all(t_mlx *ptr);
void				usage(void);

#endif
