/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

int	ft_error(char *s)
{
	ft_printf("%s", s);
	exit(1);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;

	verif_map(argc, argv);
	fdf = read_map(argv[1]);
	close(fdf.fd);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	default_params(&fdf, mlx, mlx_img);
	draw_points(fdf);
	draw_image(fdf);
	mlx_loop_hook(mlx, &hook, &fdf);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
