/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_W) && fdf->params.zoom <= 100)
		zoom_forward(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_S) && fdf->params.zoom > 1)
		zoom_backward(fdf);
	if ((!mlx_is_key_down(fdf->params.mlx, MLX_KEY_LEFT_SHIFT)
			&& mlx_is_key_down(fdf->params.mlx, MLX_KEY_U)))
		zoom_height(fdf, 1);
	if ((mlx_is_key_down(fdf->params.mlx, MLX_KEY_LEFT_SHIFT)
			&& mlx_is_key_down(fdf->params.mlx, MLX_KEY_U)))
		zoom_height(fdf, 0);
}

void	zoom_forward(t_fdf *fdf)
{
	fdf->params.zoom += 1;
	reload_image(fdf);
}

void	zoom_backward(t_fdf *fdf)
{
	fdf->params.zoom -= 1;
	reload_image(fdf);
}

void	zoom_height(t_fdf *fdf, int more)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (more)
				fdf->map[y][x].z *= 1.1;
			else
				fdf->map[y][x].z /= 1.1;
			x++;
		}
		y++;
	}
	reload_image(fdf);
}
