/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	verif_map(int ac, char **av)
{
	char	*extension;

	if (ac != 2)
		return (ft_error("Utilisation : ./fdf <map.fdf>\n"));
	extension = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if (ft_strncmp(".fdf", extension, 4) != 0)
	{
		free(extension);
		return (ft_error("Utilisation : ./fdf <map.fdf>\n"));
	}
	free(extension);
	return (0);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Impossible d'ouvrir le fichier !\n"));
	return (fd);
}
