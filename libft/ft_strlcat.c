/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:35 by bplante           #+#    #+#             */
/*   Updated: 2023/04/04 12:49:35 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_strlen.c"
#include "libft.h"

// size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
// {
// 	size_t	srcsize;
// 	size_t	dest_str_size;
// 	size_t	i;

// 	dest_str_size = ft_strlen(dest);
// 	srcsize = ft_strlen(src);
// 	if (dest && src)
// 	{
// 		i = 0;
// 		while (i + dest_str_size < destsize - 1 && i < srcsize)
// 		{
// 			*(dest + i + dest_str_size) = *(src + i);
// 			i++;
// 		}
// 	}
// 	return (dest_str_size + srcsize);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slength;
	size_t	dlength;

	j = 0;
	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (0);
	dlength = ft_strlen(dst);
	j = dlength;
	slength = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dlength)
		return (slength + dstsize);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlength + slength);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*src;
// 	char	real_dest[10];
// 	char	ft_dest[10];

// 	src = "test";
// 	bzero(real_dest, 10);
// 	real_dest[0] = 'r';
// 	real_dest[1] = 'e';
// 	bzero(ft_dest, 10);
// 	ft_dest[0] = 'r';
// 	ft_dest[1] = 'e';
// 	printf("%lu\n", strlcat(real_dest, src, 10));
// 	printf("%lu\n", ft_strlcat2(ft_dest, src, 10));
// }
