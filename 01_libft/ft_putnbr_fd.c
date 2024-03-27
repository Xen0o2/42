/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:06:52 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 22:15:18 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nn;

	if (n < 0)
	{
		nn = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nn = n;
	if (nn > 9)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd((nn % 10) + '0', fd);
}
