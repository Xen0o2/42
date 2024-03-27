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

void	projection(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_I))
		projection_isometric(fdf);
	if (mlx_is_key_down(fdf->params.mlx, MLX_KEY_N))
		projection_normal(fdf);
}

void	projection_isometric(t_fdf *fdf)
{
	fdf->params.isometric = 1;
	reload_image(fdf);
}

void	projection_normal(t_fdf *fdf)
{
	fdf->params.isometric = 0;
	reload_image(fdf);
}
