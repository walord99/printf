/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:48:37 by Ben               #+#    #+#             */
/*   Updated: 2023/04/04 12:48:38 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		n_cpy;
	int		i;
	char	*str;

	n_cpy = n;
	i = 0;
	while (++i && n_cpy)
		n_cpy /= 10;
	if (n <= 0)
		i++;
	str = ft_calloc(1, i);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i - 2] = ft_num_to_char(n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

char	ft_num_to_char(int n)
{
	if (n < 0)
		return ((n * -1) + '0');
	return (n + '0');
}
