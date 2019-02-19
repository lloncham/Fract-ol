/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:18:04 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/19 17:06:15 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init(t_mlx *f, int x, int y)
{
	if (f->choose == 1 || f->choose == 5 || f->choose == 4)
	{
		f->nb = (f->choose == 4) ? -1 : 1;
		f->c_r = x / f->zoomx + f->x1;
		f->c_i = y / f->zoomy + f->y1;
		f->z_r = 0;
		f->z_i = 0;
	}
	if (f->choose == 2)
	{
		f->nb = 1;
		f->z_r = x / f->zoomx + f->x1;
		f->z_i = y / f->zoomy + f->y1;
	}
	if (f->choose == 3)
	{
		f->c_r = 0.0694;
		f->c_i = 0;
		f->z_r = x / f->zoomx + f->x1;
		f->z_i = y / f->zoomy + f->y1;
	}
}
