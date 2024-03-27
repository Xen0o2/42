/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	default_params(t_fdf *fdf, mlx_t *mlx, mlx_image_t *mlx_img)
{
	fdf->params.angle = 0.8;
	fdf->params.isometric = 1;
	fdf->params.shift_x = WIDTH / 3;
	fdf->params.shift_y = HEIGHT / 3;
	fdf->params.z_zoom = 1;
	fdf->params.zoom = 20;
	fdf->params.bold = 0;
	fdf->params.window_height = HEIGHT;
	fdf->params.window_width = WIDTH;
	fdf->params.mlx = mlx;
	fdf->params.mlx_img = mlx_img;
}

void	apply_params(t_point *a, t_point *b, t_fdf fdf)
{
	apply_zoom(a, b, fdf);
	if (fdf.params.isometric)
	{
		isometric(a, fdf.params.angle);
		isometric(b, fdf.params.angle);
	}
	a->x += fdf.params.shift_x;
	a->y += fdf.params.shift_y;
	b->x += fdf.params.shift_x;
	b->y += fdf.params.shift_y;
}
