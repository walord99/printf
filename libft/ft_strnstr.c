/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:59:25 by bplante           #+#    #+#             */
/*   Updated: 2023/02/16 15:42:01 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_str_in_str(const char *heystack, const char *needle);

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	unsigned long	n_len;
	unsigned long	max_loop;
	unsigned long	i;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)heystack);
	if (ft_strlen(heystack) == 0 || n_len > len)
		return (NULL);
	max_loop = len - n_len;
	i = 0;
	while (i <= max_loop)
	{
		if (is_str_in_str(&heystack[i], needle))
			return ((char *)&heystack[i]);
		i++;
	}
	return (NULL);
}

static int	is_str_in_str(const char *heystack, const char *needle)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (heystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

// #include "ft_strlen.c"

// int	main(void)
// {
// 	ft_strnstr("", "", 0);
// }
