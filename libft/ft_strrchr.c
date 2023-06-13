/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:59:23 by bplante           #+#    #+#             */
/*   Updated: 2023/02/16 14:00:34 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	tlf;

	tlf = c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == tlf)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
