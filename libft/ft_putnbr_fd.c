/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:49:25 by Ben               #+#    #+#             */
/*   Updated: 2023/04/04 12:51:06 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static unsigned int	exponent(int base, int exponent);

void	ft_putnbr_fd(int n, int fd)
{
	int	n_cpy;
	int	i;
	int	power;

	n_cpy = n;
	i = 0;
	while (n_cpy && ++i)
		n_cpy /= 10;
	power = exponent(10, i - 1);
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	while (i--)
	{
		ft_putchar_fd(ft_num_to_char(n / power), fd);
		n %= power;
		power /= 10;
	}
}

static unsigned int	exponent(int base, int exponent)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}
