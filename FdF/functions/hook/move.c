/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	move(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_UP))
		move_up(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_DOWN))
		move_down(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_RIGHT))
		move_right(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_LEFT))
		move_left(fdf);
}

void	move_up(t_fdf *fdf)
{
	fdf->params.shift_y -= 5;
	reload_image(fdf);
}

void	move_down(t_fdf *fdf)
{
	fdf->params.shift_y += 5;
	reload_image(fdf);
}

void	move_right(t_fdf *fdf)
{
	fdf->params.shift_x += 5;
	reload_image(fdf);
}

void	move_left(t_fdf *fdf)
{
	fdf->params.shift_x -= 5;
	reload_image(fdf);
}
