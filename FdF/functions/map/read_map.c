/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

void	free_all_map(t_fdf *fdf, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
		free(fdf->map[i++]);
	free(fdf->map);
	ft_error("Erreur d'allocation !\n");
}

int	extract_line(t_fdf *fdf, char *line, int i)
{
	char	**all;
	int		x;

	x = 0;
	all = ft_split(line, " \n");
	fdf->map[i] = malloc((ft_tablen(all)) * sizeof(t_point));
	if (!fdf->map[i])
		free_all_map(fdf, i);
	while (all[x])
	{
		fdf->map[i][x].x = x;
		fdf->map[i][x].y = i;
		fdf->map[i][x].z = ft_atoi(all[x]);
		free(all[x]);
		fdf->map[i][x++].is_last = 0;
	}
	free(line);
	free(all);
	fdf->map[i][--x].is_last = 1;
	return (x);
}

void	get_map(t_fdf *fdf)
{
	char	*line;
	int		i;
	int		x;

	fdf->map = malloc(fdf->height * sizeof(int *));
	if (!fdf->map)
		ft_error("Erreur d'allocation !\n");
	i = 0;
	line = get_next_line(fdf->fd);
	while (line)
	{
		x = extract_line(fdf, line, i);
		line = get_next_line(fdf->fd);
		i++;
	}
	free(line);
	fdf->width = x + 1;
	close(fdf->fd);
}

t_fdf	read_map(char *file)
{
	t_fdf	fdf;

	fdf.fd = ft_open(file);
	fdf.height = get_height(fdf.fd);
	fdf.fd = ft_open(file);
	get_map(&fdf);
	return (fdf);
}
