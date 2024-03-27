/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	init_line(t_line *line, t_point a, t_point b)
{
	line->distance_x = abs(b.x - a.x);
	line->distance_y = -abs(b.y - a.y);
	line->error = line->distance_x + line->distance_y;
	line->sign_x = (a.x < b.x) * 2 - 1;
	line->sign_y = (a.y < b.y) * 2 - 1;
	if (b.z || a.z)
		line->color = PINK;
	else
		line->color = WHITE;
	if (b.z != a.z)
		line->color = GREEN;
}

int	condition(t_line *line, t_point *a, t_point *b)
{
	if (line->error2 >= line->distance_y)
	{
		if (a->x == b->x)
			return (1);
		line->error += line->distance_y;
		a->x += line->sign_x;
	}
	if (line->error2 <= line->distance_x)
	{
		if (a->y == b->y)
			return (1);
		line->error += line->distance_x;
		a->y += line->sign_y;
	}
	return (0);
}

void	line(t_point a, t_point b, t_fdf fdf)
{
	t_line	line;

	apply_params(&a, &b, fdf);
	init_line(&line, a, b);
	while (1)
	{
		if ((a.x > 0 && a.y > 0
				&& a.x < (int) fdf.params.mlx_img->width
				&& a.y < (int) fdf.params.mlx_img->height))
		{
			mlx_put_pixel(fdf.params.mlx_img, a.x, a.y, line.color);
			if (fdf.params.bold)
			{
				mlx_put_pixel(fdf.params.mlx_img, a.x + 1, a.y, line.color);
				mlx_put_pixel(fdf.params.mlx_img, a.x, a.y + 1, line.color);
				mlx_put_pixel(fdf.params.mlx_img, a.x + 1, a.y + 1, line.color);
			}
		}
		if (a.x == b.x && a.y == b.y)
			break ;
		line.error2 = 2 * line.error;
		if (condition(&line, &a, &b))
			break ;
	}
}

void	draw_points(t_fdf fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf.height)
	{
		x = 0;
		while (x < fdf.width)
		{
			if (y < fdf.height - 1)
				line(fdf.map[y][x], fdf.map[y + 1][x], fdf);
			if (!fdf.map[y][x].is_last)
				line(fdf.map[y][x], fdf.map[y][x + 1], fdf);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fdf.params.mlx, fdf.params.mlx_img, 0, 0);
}

void	draw_image(t_fdf fdf)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("fdf.png");
	img = mlx_texture_to_image(fdf.params.mlx, texture);
	mlx_image_to_window(fdf.params.mlx, img, 0, 0);
	mlx_delete_texture(texture);
}
