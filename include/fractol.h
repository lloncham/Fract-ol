/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:13:06 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/14 16:56:05 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"


typedef	struct		s_mlx
{
	int				*mlx;
	int				*win;
	int				*img;
	int				*img_data;
	int				color;
	int				zoom;
	double				iter;
	int				choose;
	double			imgx;
	double			imgy;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				size_h;
	int				size_w;
}					t_mlx;

void				error(char *str);
int					clear_img(t_mlx *ptr);
void				ft_put_pixel(t_mlx *ptr, int y, int x, int color);
int					draw_fract(t_mlx *f);
int					init_color(t_mlx *f, int i);
void				init_fract(t_mlx *f, int x, int y);
t_mlx				init_mandelbrot(t_mlx ptr);
t_mlx				init_julia(t_mlx ptr);

#endif
