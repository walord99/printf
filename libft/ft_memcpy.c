/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:03:45 by bplante           #+#    #+#             */
/*   Updated: 2023/04/04 12:49:20 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	unsigned const char	*src_ptr;

	dst_ptr = dest;
	src_ptr = src;
	if (dest == NULL || src == NULL)
		return (dest);
	while (n--)
		*(dst_ptr + n) = *(src_ptr + n);
	return (dest);
}
