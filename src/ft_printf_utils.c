/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:34:42 by bplante           #+#    #+#             */
/*   Updated: 2023/05/23 11:55:52 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_e(char *str, t_options *options)
{
	int	i;

	i = 0;
	if (options->specifier == 'c')
		return (write(1, &str[0], 1));
	while (str[i])
	{
		if (write(1, str + i, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	number_char_amount(int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (n / j != 0)
	{
		i++;
		j *= 10;
	}
	return (1);
}

char	*char_to_str(char c)
{
	char	*output;

	output = ft_calloc(2, sizeof(char));
	if (!output)
		return (NULL);
	output[0] = c;
	return (output);
}
