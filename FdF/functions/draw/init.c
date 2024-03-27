/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	apply_zoom(t_point *a, t_point *b, t_fdf fdf)
{
	a->x *= fdf.params.zoom;
	a->y *= fdf.params.zoom;
	b->x *= fdf.params.zoom;
	b->y *= fdf.params.zoom;
	a->z *= fdf.params.z_zoom;
	b->z *= fdf.params.z_zoom;
}

void	isometric(t_point *point, double angle)
{
	point->x = (angle * point->x - angle * point->y);
	point->y = (angle * point->x) + (point->y) - (point->z);
}
