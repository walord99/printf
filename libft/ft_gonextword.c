/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gonextword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ben <benplante99@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:58 by Ben               #+#    #+#             */
/*   Updated: 2023/04/04 13:11:25 by Ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_go_next_word(const char *str, char delemiter)
{
	int		next_word_ready;
	size_t	i;

	i = 0;
	next_word_ready = 0;
	while (str[i])
	{
		if (str[i] != delemiter && next_word_ready)
			return (i);
		else if (str[i] == delemiter)
			next_word_ready = 1;
		i++;
	}
	return (i);
}
