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

void	rotate(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_D) && fdf->params.angle < 0.8)
		rotate_right(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_A) && fdf->params.angle > -0.8)
		rotate_left(fdf);
}

void	rotate_right(t_fdf *fdf)
{
	fdf->params.angle += 0.02;
	reload_image(fdf);
}

void	rotate_left(t_fdf *fdf)
{
	fdf->params.angle -= 0.02;
	reload_image(fdf);
}
