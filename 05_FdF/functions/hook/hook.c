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

void	reload_image(t_fdf *fdf)
{
	mlx_delete_image(fdf->params.mlx, fdf->params.mlx_img);
	fdf->params.mlx_img = mlx_new_image(fdf->params.mlx, WIDTH, HEIGHT);
	draw_points(*fdf);
}

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	move(fdf);
	projection(fdf);
	zoom(fdf);
	rotate(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->params.mlx);
	if ((!mlx_is_key_down(fdf->params.mlx, MLX_KEY_LEFT_SHIFT)
			&& mlx_is_key_down(fdf->params.mlx, MLX_KEY_B)))
	{
		fdf->params.bold = 1;
		reload_image(fdf);
	}
	if ((mlx_is_key_down(fdf->params.mlx, MLX_KEY_LEFT_SHIFT)
			&& mlx_is_key_down(fdf->params.mlx, MLX_KEY_B)))
	{
		fdf->params.bold = 0;
		reload_image(fdf);
	}
}
