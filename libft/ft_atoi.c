/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:25 by bplante           #+#    #+#             */
/*   Updated: 2023/02/16 17:01:59 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			sign;

	if (str == NULL)
		return (0);
	i = 0;
	nb = 0;
	sign = 1;
	if (str)
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			nb = nb * 10 + str[i++] - '0';
	}
	return (sign * nb);
}
