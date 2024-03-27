/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:18:18 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/16 15:14:50 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WHITE 0xFFFFFFFF
# define GREEN 0x00FF00FF
# define PINK  0xFF00F4FF

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include "MLX/include/MLX42/MLX42.h"
# define WIDTH 2000
# define HEIGHT 1000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_split
{
	char	**tab;
	int		i;
	int		j;
	int		sep;
	int		length;
}	t_split;

typedef struct s_point
{
	int		x;
	int		y;
	double	z;
	int		is_last;
}	t_point;

typedef struct s_line
{
	float	distance_x;
	float	sign_x;
	float	distance_y;
	float	sign_y;
	float	error;
	float	error2;
	int		color;
}	t_line;

typedef struct s_params
{
	int			zoom;
	int			z_zoom;
	double		angle;
	int			shift_x;
	int			shift_y;
	int			isometric;
	int			bold;
	int			window_height;
	int			window_width;
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
}	t_params;

typedef struct s_fdf
{
	int			height;
	int			width;
	int			fd;
	t_params	params;
	t_point		**map;
}	t_fdf;

typedef struct s_join
{
	char	*result;
	int		i;
	int		x;
}	t_join;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_printf(const char *placeholder, ...);
int		ft_putchar_fd(char c, int fd, int *error);
int		ft_putstr_fd(char *s, int fd, int *error);
int		ft_putnbr_fd(long n, int fd, int *error);
int		ft_putunbr_fd(unsigned long n, int fd, int *error);
int		ft_toupper(int c);
int		ft_strlen(char *s);
int		ft_tablen(char **s);
int		ft_atoi(const char *s);
char	**ft_split(char const *s, char *sep);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		next_word_length(char const *s, char *sep);
int		in_sep(char c, char *sep);
void	apply_zoom(t_point *a, t_point *b, t_fdf fdf);
void	isometric(t_point *point, double angle);
void	init_line(t_line *line, t_point a, t_point b);
int		condition(t_line *line, t_point *a, t_point *b);
void	line(t_point a, t_point b, t_fdf fdf);
void	draw_points(t_fdf fdf);
void	hook(void *param);
int		ft_open(char *file);
int		get_height(int fd);
void	get_map(t_fdf *fdf);
t_fdf	read_map(char *file);
void	default_params(t_fdf *fdf, mlx_t *mlx, mlx_image_t *mlx_img);
void	apply_params(t_point *a, t_point *b, t_fdf fdf);
int		ft_error(char *s);
int		verif_map(int ac, char **av);
void	reload_image(t_fdf *fdf);
void	move(t_fdf *fdf);
void	move_up(t_fdf *fdf);
void	move_down(t_fdf *fdf);
void	move_right(t_fdf *fdf);
void	move_left(t_fdf *fdf);
void	projection(t_fdf *fdf);
void	projection_isometric(t_fdf *fdf);
void	projection_normal(t_fdf *fdf);
void	zoom(t_fdf *fdf);
void	zoom_forward(t_fdf *fdf);
void	zoom_backward(t_fdf *fdf);
void	zoom_height(t_fdf *fdf, int more);
void	rotate(t_fdf *fdf);
void	rotate_right(t_fdf *fdf);
void	rotate_left(t_fdf *fdf);
void	draw_image(t_fdf fdf);

#endif
