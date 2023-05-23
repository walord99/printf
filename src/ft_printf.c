/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:16:27 by bplante           #+#    #+#             */
/*   Updated: 2023/05/23 11:55:53 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		char_amount;
	va_list	args;

	char_amount = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			if (write(1, str, 1) == -1)
				return (-1);
			char_amount++;
		}
		else
		{
			str++;
			char_amount = format(args, (char **)&str, char_amount);
			if (char_amount == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (char_amount);
}

int	format(va_list args, char **str, int char_amount)
{
	char		*output;
	int			i;
	t_options	*options;

	options = ft_calloc(sizeof(t_options), 1);
	if (!options)
		return (-1);
	if (get_options(*str, options) == -1)
		return (-1);
	*str = ft_strchr(*str, options->specifier);
	output = specifier_selector(args, options->specifier);
	if (!output)
	{
		free(options);
		return (-1);
	}
	i = ft_putstr_e(output, options);
	free(options);
	free(output);
	if (i == -1)
		return (-1);
	return (char_amount + i);
}

char	*specifier_selector(va_list args, char c)
{
	if (c == 'c')
		return (char_to_str(va_arg(args, unsigned int)));
	else if (c == 's')
		return (arg_to_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'x')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_strdup("%"));
	else if (c == 'u')
		return (arg_to_uint(va_arg(args, unsigned int)));
	else
		return (arg_to_ptr(va_arg(args, void *)));
}

// char	*apply_options(char *str, t_options options)
// {
// 	if(options.width != 0)
// 	{

// 	}
// }
